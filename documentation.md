# POSIX

---

What we will need here:

1. Thread Creation
2. Thread Destroy
3. Thread Communication
4. Thread Synchronization

---

You will need to include this file to work with `pThreads` in your Project: 

```c
#include <pthread.h>
```

Additional information  about pThreads can always be found in the [doc](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/).

## 1. pThread - create()

This will launch a new thread to do some work on another CPU.

```c
 #include <pthread.h>

 int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                    void *(*start_routine) (void *), void *arg);
```



### 1.1. Simple pThread_create() - Single Thread

```c
#include <pthread.h>

void* thread_function(void* arg)
{
    //Do some thread work here...
    pthread_extit(0);
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
```



### 1.2. Advanced pThread_create() - Multiple Threads

```c
#include <pthread.h>

void* thread_function(void* arg)
{
    //Do some thread work here...
    pthread_extit(0);
}

int main(int argc, char **argsv)
{
    int numberOfThreads = 100;
    
    //Define a Single pThread ID
    pthread_t thread_ids[numberOfThreads];
    
    // Create Attributes for Thread
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
    for(int i = 0; i < 100, i++)
    {
        //We will share the value i to the thread_function
        pthread_create(&thread_id[i], &attr, thread_function, &i);
    }
    
	
    // Wait until ALL thread are done
    for (int i = 0; i < 100; i++)
    {
    	pthread_join(thread_id[i], NULL);    
    }
    
    
    return 0;   
}
```

## 2. pThread - destroy()

You may want to stop a Thread form executing for whatever reason.

```c
#include <signal.h>

int pthread_kill(pthread_t thread, int sig);
```

### 2.1 pThread_kill()

```c
#include <pthread.h>
#include <signal.h>

void* thread_function(void* arg)
{
    //Do some thread work here...
    pthread_extit(0);
}

int main(int argc, char **argsv)
{
    //Define a Single pThread ID
    pthread_t thread_id;
    
    // Create Attributes for Thread (this is not necessary! you can also use NULL)
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
	pthread_create(&thread_id, &attr, thread_function, NULL);
	
    //Now kill the thread again
    pthread_kill(thread_id, 0);
    
    return 0;   
}
```



## 3. pThread - Communication

You may want to send Data from your main()-loop to a thread and vice versa.

To accomplish communication a nice way to do it are pointers to a `struct`

```c
#include <pthread.h>

struct myStructTemplate
{
    int number;
    long longNumber;
}

void* thread_function(void* arg)
{
   struct myStructTemplate *my_struct = (struct myStructTemplate*) arg;
   my_struct->number = 11;
   my_struct->longNumber = 11111111199;
    
   pthread_extit(0);
}

int main(int argc, char **argsv)
{
    struct myStructTemplate myStruct[2]; 
    
    //Define pThreads 
    pthread_t thread_1 thread_2;
    
    //Create threads and share pointer
	pthread_create(&thread_1, NULL, thread_function, &myStruct[0]);
    pthread_create(&thread_2, NULL, thread_function, &myStruct[0]);
	
    // Join/Wait on threads
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    
    pintf("Number_1: %d, %ld", myStruct[0].number, myStruct[0].longNumber);
    pintf("Number_2: %d, %ld", myStruct[1].number, myStruct[1].longNumber);
    
    return 0;   
}
```



## 4. pThread -  Synchronization

If you run multiple thread and they share a common value there will be some inexplicable behavior.
May be known as `race conditions`.
To bypass this issue you can use `mutexes`.

## 4.1. pThread - Mutex

```c
#include <pthread.h>

int global_var = 0;
pthread_mutex_t mutex;

void* thread_function(void* arg)
{
   pthread_mutex_lock(&mutex);
   global_var++;
   pthread_mutex_unlock(%mutex);
   pthread_extit(0);
}

int main(int argc, char **argsv)
{
    //Define pThreads 
    pthread_t thread_1 thread_2;
    
    //Init mutex
    pthread_mutex_init(&mutex, NULL);
    
    //Create threads
	pthread_create(&thread_1, NULL, thread_function, NULL);
    pthread_create(&thread_2, NULL, thread_function, NULL);
	
    // Join/Wait on threads
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    
    return 0;   
}
```





## 5. pThread additional stuff

### 5.1 pThread_setname() - Naming pThreads

```c
#include <pthread.h>

void* thread_function(void* arg)
{
    //Do some thread work here...
    pthread_extit(0);
}

int main(int argc, char **argsv)
{
    //Define a Single pThread ID
    pthread_t thread_id;
    
    // Create Attributes for Thread (this is not necessary! you can also use NULL)
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
	pthread_create(&thread_id, &attr, thread_function, &i);
    
    //Here we will Create a name for our Thread
    char buffer[20];
    snprintf(buffer, sizeof(buffer), "%C%i", "Thread-", 1);
    pthread_setname_np(thread_id,  buffer);

    
    // Wait until thread is done
    pthread_join(thread_id, NULL);
    
    
    return 0;   
}
```

