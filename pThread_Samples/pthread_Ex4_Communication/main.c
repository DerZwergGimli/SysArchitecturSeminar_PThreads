#include <pthread.h>
#include <stdio.h>

struct myStructTemplate
{
    int number;
    long longNumber;
};

void* thread_function1(void* arg)
{
   struct myStructTemplate *my_struct = (struct myStructTemplate*) arg;
   my_struct->number = 11;
   my_struct->longNumber = 111111111;
    
   pthread_exit(0);
}

void* thread_function2(void* arg)
{
   struct myStructTemplate *my_struct = (struct myStructTemplate*) arg;
   my_struct->number = 22;
   my_struct->longNumber = 222222222;
    
   pthread_exit(0);
}

int main(int argc, char **argsv)
{
    struct myStructTemplate myStruct[2]; 
    
    //Define pThreads 
    pthread_t thread_1, thread_2;
    
    //Create threads and share pointer
	pthread_create(&thread_1, NULL, thread_function1, &myStruct[0]);
    pthread_create(&thread_2, NULL, thread_function2, &myStruct[1]);
	
    // Join/Wait on threads
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    
    printf("Number_1: %d, %ld \n", myStruct[0].number, myStruct[0].longNumber);
    printf("Number_2: %d, %ld \n", myStruct[1].number, myStruct[1].longNumber);
    
    pthread_exit(NULL);  
}