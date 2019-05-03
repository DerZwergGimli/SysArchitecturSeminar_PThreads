#include <pthread.h>

void* thread_function(void* arg)
{
    //Do some thread work here...
    pthread_exit(0);
}

int main(int argc, char **argsv)
{
    //Define a Single pThread ID
    pthread_t thread_id;
    
    // Create Attributes for Thread (this is not necessary! you can also use NULL)
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
    pthread_create(&thread_id, &attr, thread_function, NULL);
    //pthread_create(&tid, NULL, thread_function, &i);
    
    // Wait until thread is done
    pthread_join(thread_id, NULL);
    
    
    return 0;   
}