#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 
#include <unistd.h>


#define number_of_threads 2

/* create thread argument struct for thr_func() */
typedef struct _thread_data_t {
  int tid;
  double stuff;
} thread_data_t;


//Thread function
void *thread_function(void *arg){
    thread_data_t *data = (thread_data_t *)arg;

    printf("Hello from thread_function, thread id: %d\n", data->tid);
    sleep(3);

    pthread_exit(NULL);
}

int main(int argc, char **argsv) {
    pthread_t thr[number_of_threads];
    int i, rc;
    /* create a thread_data_t argument array */
    thread_data_t thr_data[number_of_threads];

    /*create threads */
    for (i = 0; i < number_of_threads; ++i){
        thr_data[i].tid = i;

        if ((rc = pthread_create(&thr[i], NULL, thread_function, &thr_data[i]))){
            fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
            return EXIT_FAILURE;
        }
        
    }
    
    
    
    for (i = 0; i < number_of_threads; ++i){
        pthread_join(thr[i], NULL);
    }

    return EXIT_SUCCESS;
}
