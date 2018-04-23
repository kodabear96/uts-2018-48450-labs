#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>

/* Function prototypes */
void initialiseThreads(pthread_t*, pthread_t*);
void *thread1(void *arg);
void *thread2(void *arg);

/* Globals */
static int Sum = 0;
pthread_mutex_t Mutex; /* Mutex lock */
sem_t Semaphore1, Semaphore2; /* Semaphores */

/* Main function */
int main(int argc, char*argv[]) {
  /* Create thread IDs */
  pthread_t tid1, tid2;

  /* Init threads */
  initialiseThreads(&tid1, &tid2);

  /* Signal Semaphore2 */
  sem_post(&Semaphore2);

  /* Wait for thread termination and status */
  void *threadResult;
  if (pthread_join(tid1, &threadResult)) {
    errno = *((int *)threadResult);
    perror("Thread 1 failed");
    return EXIT_FAILURE;
  } else if (pthread_join(tid2, &threadResult)) {
    errno = *((int *)threadResult);
    perror("Thread 2 failed");
    return EXIT_FAILURE;
  }
  free(threadResult);

  return EXIT_SUCCESS;
}

void initialiseThreads(pthread_t *tid1, pthread_t *tid2) {
  /* Initialise mutex lock */
  pthread_mutex_init(&Mutex, NULL);

  /* Initialise semaphores and set to 0 */
  sem_init(&Semaphore1, 0, 0);
  sem_init(&Semaphore2, 0, 0);

  /* Create thread attributes */
  pthread_attr_t attr;

  /* Initialise thread attributes */
  pthread_attr_init(&attr);

  /* Create threads */
  pthread_create(tid1, &attr, &thread1, NULL);
  pthread_create(tid2, &attr, &thread2, NULL);

  /* Destroy thread attributes */
  pthread_attr_destroy(&attr);
}

void *thread1(void *arg) {
  /* Wait for Semaphore1 */
  sem_wait(&Semaphore1);

  /* Mutex lock program */
  pthread_mutex_lock(&Mutex);

  /* Perform calculations */
  int i;
  for (i = 1; i <= 100 ; i++) {
    Sum += i;
  }

  /* Print thread information */
  printf("Thread 1\n");
  printf("%d\n", Sum);

  /* Release mutex lock */
  pthread_mutex_unlock(&Mutex);

  return EXIT_SUCCESS;
}

void *thread2(void *arg) {
  /* Wait for Semaphore2 */
  sem_wait(&Semaphore2);

  /* Mutex lock program */
  pthread_mutex_lock(&Mutex);

  /* Perform calculations */
  int i;
  for (i = -100; i < 0; i++) {
    Sum += i;
  }

  /* Print thread information */
  printf("Thread 2\n");
  printf("%d\n", Sum);

  /* Release mutex lock */
  pthread_mutex_unlock(&Mutex);

  /* Signal Semaphore1 */
  sem_post(&Semaphore1);

  return EXIT_SUCCESS;
}
