#include <pthread.h>
#include <signal.h>

void* thread_function(void* arg)
{
     //Do some thread work here...
    for (int i = 0; i < 10; i++)
    {
        sleep(1);
    }

    pthread_exit(NULL);
}

int main(int argc, char **argsv)
{
    int numberOfThreads = 100;
    
    //Define a Single pThread ID
    pthread_t thread_ids[numberOfThreads];
    
    // Create Attributes for Thread
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
    for(int i = 0; i < numberOfThreads; i++)
    {
        //We will share the value i to the thread_function
        pthread_create(&thread_ids[i], &attr, thread_function, &i);
        
        //Naming all Threads 
        char name[16] = { 0 };
        snprintf(name, sizeof(name), "Thread-%03d", i);
        pthread_setname_np(thread_ids[i], name);
    }

    //sleep(3);
    
    for (int i = 0; i < numberOfThreads; i++)
    {
        if((i%2) == 0)
        {   
            //Now cancel Thread
            pthread_cancel(thread_ids[i]);
        }
        i++;
    }
    
    
	
    // Wait until ALL thread are done
    for (int i = 0; i < numberOfThreads; i++)
    {
    	pthread_join(thread_ids[i], NULL);    
    }
    
    pthread_exit(NULL);
}