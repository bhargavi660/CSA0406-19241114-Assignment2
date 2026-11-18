#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <fcntl.h>

#define MB (1024 * 1024)

double get_time(void)
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return t.tv_sec + t.tv_nsec / 1000000000.0;
}

void pipe_test(size_t size)
{
    int fd[2];
    char *buffer = malloc(size);

    if (!buffer || pipe(fd) == -1) {
        perror("pipe/malloc");
        exit(1);
    }

    memset(buffer, 'A', size);
    pid_t pid = fork();

    if (pid == 0) {
        close(fd[1]);
        char temp[65536];
        ssize_t n;

        while ((n = read(fd[0], temp, sizeof(temp))) > 0) {}
        close(fd[0]);
        free(buffer);
        _exit(0);
    }

    close(fd[0]);
    double start = get_time();
    size_t sent = 0;

    while (sent < size) {
        size_t chunk = size - sent;
        if (chunk > 65536) chunk = 65536;

        ssize_t n = write(fd[1], buffer + sent, chunk);
        if (n <= 0) {
            perror("write");
            exit(1);
        }
        sent += (size_t)n;
    }

    close(fd[1]);
    waitpid(pid, NULL, 0);
    printf("Pipe: %.6f seconds\n", get_time() - start);
    free(buffer);
}

void shared_memory_test(size_t size)
{
    int fd = shm_open("/benchmark_shm", O_CREAT | O_RDWR, 0600);
    if (fd == -1 || ftruncate(fd, (off_t)size) == -1) {
        perror("shared memory");
        exit(1);
    }

    char *data = mmap(NULL, size, PROT_READ | PROT_WRITE,
                      MAP_SHARED, fd, 0);
    if (data == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    pid_t pid = fork();
    if (pid == 0) {
        volatile unsigned long sum = 0;
        for (size_t i = 0; i < size; i += 4096)
            sum += (unsigned char)data[i];
        (void)sum;
        munmap(data, size);
        close(fd);
        _exit(0);
    }

    double start = get_time();
    memset(data, 'A', size);
    waitpid(pid, NULL, 0);

    printf("Shared Memory: %.6f seconds\n", get_time() - start);

    munmap(data, size);
    close(fd);
    shm_unlink("/benchmark_shm");
}

int main(void)
{
    size_t sizes[] = {1 * MB, 10 * MB, 100 * MB};

    for (int i = 0; i < 3; i++) {
        printf("\nTransfer size: %zu MB\n", sizes[i] / MB);
        pipe_test(sizes[i]);
        shared_memory_test(sizes[i]);
    }

    return 0;
}
