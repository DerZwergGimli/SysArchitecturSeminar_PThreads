#include <pthread.h>
#include <stdio.h>

int global_var = 0;
pthread_mutex_t mutex;

void* thread_function(void* arg)
{
   sleep(1);

   pthread_mutex_lock(&mutex);
   //pthread_mutex_trylock(&mutex);
   global_var++;
   pthread_mutex_unlock(&mutex);

   printf("%i\n", global_var);

   pthread_exit(NULL);
}

int main(int argc, char **argsv)
{
    //Define pThreads 
    pthread_t thread_1, thread_2, thread_3;
    
    //Init mutex
    pthread_mutex_init(&mutex, NULL);
    
    //Create threads
	pthread_create(&thread_1, NULL, thread_function, NULL);
    pthread_create(&thread_2, NULL, thread_function, NULL);
    pthread_create(&thread_3, NULL, thread_function, NULL);

    
	
    // Join/Wait on threads
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    pthread_join(thread_3, NULL);
    
    pthread_exit(NULL);
}