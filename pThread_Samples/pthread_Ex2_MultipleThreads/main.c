#include <pthread.h>

void* thread_function(void* arg)
{
    for (int i = 0; i < 10000; i++)
    {
        int sum;
        printf("Hello from multiple Thread \n");
        for (int j = 0; j < 100000000; j++)
        {  
            sum += j;
        }
        
        
    }
    
    pthread_exit(NULL);
}

int main(int argc, char **argsv)
{
    int numberOfThreads = 5;    
    
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
    
    
	
    // Wait until ALL thread are done
    for (int i = 0; i < numberOfThreads; i++)
    {
    	pthread_join(thread_ids[i], NULL);    
    }
    
    
    pthread_exit(NULL);
}