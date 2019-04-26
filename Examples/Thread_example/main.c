#include<stdio.h>
#include<pthread.h>


void myThread(void * param){
    //TODO: Do smth useful
    int mCount = *(int *) param;
    mCount++;

    printf("Count %d", mCount);
    // pass the calue to the main process
    pthread_exit(0);
}

int main() {
	
    // Thread ID
    pthread_t tid; 

    // Thread Attributes: TCB : Thread Control Block
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
    // Parameter to pass to the Thread
    int count = 0;

    // Start Thread
    pthread_create(&tid,        // Thread ID
                    &attr,      // TCB
                    myThread,   // function Callback (pointer) of the Thread
                    &count);    // parameter to pass to the Thread

    // wait until Thread is done
    pthread_join(&tid, 
                NULL);  // param to capture the value passed by 
	return 0;
}