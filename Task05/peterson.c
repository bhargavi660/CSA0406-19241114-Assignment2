#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>

#define ITERATIONS 100000

atomic_int flag[2] = {0, 0};
atomic_int turn = 0;

int shared_counter = 0;

void *process(void *arg)
{
    int id = *(int *)arg;
    int other = 1 - id;

    for (int i = 0; i < ITERATIONS; i++) {
        atomic_store(&flag[id], 1);
        atomic_store(&turn, other);

        while (atomic_load(&flag[other]) &&
               atomic_load(&turn) == other) {
            /* Wait for the other process */
        }

        shared_counter++;

        atomic_store(&flag[id], 0);
    }

    return NULL;
}

int main(void)
{
    pthread_t threads[2];
    int ids[2] = {0, 1};

    pthread_create(&threads[0], NULL, process, &ids[0]);
    pthread_create(&threads[1], NULL, process, &ids[1]);

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    printf("Final counter: %d\n", shared_counter);
    printf("Expected counter: %d\n", 2 * ITERATIONS);

    return 0;
}
