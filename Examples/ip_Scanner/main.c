#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hosts_struct
{
    int number;
    bool online;
};



// Thread function to ping a host
void* scanForIP(void* arg){

    struct hosts_struct *host = (struct hosts_struct*) arg;

    int *variable_prt = (int*) arg;
    int variable = *variable_prt;

    int x;
    x = system("ping -c1 -w1 8.8.8.8 > /dev/null 2>&1");
    if(x == 0)
    {
        printf("Success \n");
        host->online = true;
    }
    else
    {
        printf("Failed \n");
        host->online = false;
    }

    sleep(3);

    
}



int main(int argc, char **argsv) {
    
    printf("App started... \n");
    bool workToDo = true;

    struct hosts_struct hosts[100];

    int variable = 8;
    while (workToDo)
    {
        // Thread ID
        pthread_t tid[100];
        

        // Create Attributes
        pthread_attr_t attr;
        pthread_attr_init(&attr);

        for (int i = 0; i < 100; i++)
        {
            pthread_create(&tid[i], &attr, scanForIP, &variable);
            hosts[i].number = i;

            //Setting a Thread name
            char buffer[20];
            snprintf(buffer, sizeof(buffer), "%C%i", "Thread-", i);
            printf(buffer);
            int rc = pthread_setname_np(tid[i],  buffer);
            //pthread_join(tid, NULL);
            //sleep(2);
        }

        for (int i = 0; i < 100; i++)
        {
            
            // Wait until thread is done
            pthread_join(tid[i], NULL);
            printf("HostName: %d %d \n", hosts[i].number, hosts[i].online);

        }
        



        workToDo = false;
    }
    


    

    return 0;
}

