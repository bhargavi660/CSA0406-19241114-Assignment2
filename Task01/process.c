
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t children[3];

    printf("Parent Process Started\n");
    printf("Parent PID: %d\n", getpid());

    for (int i = 0; i < 3; i++) {
        children[i] = fork();

        if (children[i] < 0) {
            perror("fork failed");
            exit(1);
        }

        if (children[i] == 0) {
            printf("Child %d created | PID: %d | Parent PID: %d\n",
                   i + 1, getpid(), getppid());

            sleep(120);
            printf("Child %d completed\n", i + 1);
            exit(0);
        }
    }

    printf("\nChild processes created:\n");
    for (int i = 0; i < 3; i++) {
        printf("Child PID: %d\n", children[i]);
    }

    for (int i = 0; i < 3; i++) {
        waitpid(children[i], NULL, 0);
    }

    printf("\nAll child processes completed.\n");

    return 0;
}
