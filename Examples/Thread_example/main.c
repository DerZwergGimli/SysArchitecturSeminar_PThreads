#include<stdio.h>
#include<pthread.h>

#include "main.h"

// Parameter to pass to the Thread
int count = 0;

// Returned variable to the main routine
int thread_rt = 0;

// Thread Mutex
pthread_mutex_t mutex; 

// Thread info struc
// Not used yet
typedef struct
{
    pthread_t tid;
    pthread_attr_t attr;
    u_int16_t thread_num;
} thread_struct;


/**
 * Thread routine
 * 
 * */
void myThread(void * param){
    //TODO: Do smth useful
    //int mCount = *(int *) param;
    //mCount++;
    pthread_mutex_lock(&mutex);

    *(int *) param += 1 ;

    printf("Count %d \n", *(int *) param);

    pthread_mutex_unlock(&mutex);

    // pass the calue to the main process
    pthread_exit((int *) param);
}

int main() {
	
    // Thread ID
    pthread_t tid; 

    // Create an Array of Thread ID's
    pthread_t tidArray[MAX_NUM_OF_THREADS];

    // Thread Attributes: TCB : Thread Control Block
    pthread_attr_t attr;

    // Create an Array of Thread Attributes (TCB)
    pthread_attr_t attrArray[MAX_NUM_OF_THREADS];

    // initialize all the Attributes
    for(size_t i = 0; i < MAX_NUM_OF_THREADS; i++)
    {
        pthread_attr_init(attrArray+i);
    }
    pthread_attr_init(&attr);
    
    

    // Start Thread
    pthread_create(&tid,        // Thread ID
                    &attr,      // TCB
                    myThread,   // function Callback (pointer) of the Thread
                    &count);    // parameter to pass to the Thread
    
    // Start all Threads
    for(size_t i = 0; i < MAX_NUM_OF_THREADS; i++)
    {
        pthread_create(tidArray+i, attrArray+i, myThread, &count);
        // NOTE: here, every Thread will run the same routine (function)
    }
    
    
    // wait until Thread is done
    for(size_t i = 0; i < MAX_NUM_OF_THREADS; i++)
    {
        pthread_join(&tidArray[i], 
                &thread_rt);  // param to capture the value passed by 
    }
    
    printf("Count returned: %d \n", thread_rt); // still returning 0 ..
	return 0;   
}