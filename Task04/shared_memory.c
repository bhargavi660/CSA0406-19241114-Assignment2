#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>

#define SHM_NAME "/weather_data"
#define COUNT 6

int main(void)
{
    int fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);

    if (fd == -1) {
        perror("shm_open");
        return 1;
    }

    if (ftruncate(fd, COUNT * sizeof(int)) == -1) {
        perror("ftruncate");
        shm_unlink(SHM_NAME);
        return 1;
    }

    int *data = mmap(NULL, COUNT * sizeof(int),
                     PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if (data == MAP_FAILED) {
        perror("mmap");
        close(fd);
        shm_unlink(SHM_NAME);
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0) {
        sleep(1);

        int sum = 0, max = 0;

        for (int i = 0; i < COUNT; i++) {
            sum += data[i];
            if (data[i] > max)
                max = data[i];
        }

        printf("analyser: %d readings, average %.1f, max %d\n",
               COUNT, (double)sum / COUNT, max);

        munmap(data, COUNT * sizeof(int));
        close(fd);
        _exit(0);
    }

    if (pid < 0) {
        perror("fork");
        munmap(data, COUNT * sizeof(int));
        close(fd);
        shm_unlink(SHM_NAME);
        return 1;
    }

    int readings[COUNT] = {31, 33, 36, 34, 41, 38};

    for (int i = 0; i < COUNT; i++)
        data[i] = readings[i];

    printf("reader: shared memory updated\n");

    waitpid(pid, NULL, 0);

    munmap(data, COUNT * sizeof(int));
    close(fd);
    shm_unlink(SHM_NAME);

    return 0;
}
