#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct hosts_struct
{
    int ip;
    int number;
    bool online;
};



// Thread function to ping a host
void* scanForIP(void* arg){

    struct hosts_struct *host = (struct hosts_struct*) arg;

    int *variable_prt = (int*) arg;
    int variable = *variable_prt;

    int x;
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "ping -c1 -w1 192.168.179.%d > /dev/null 2>&1", variable);
    x = system(buffer);
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

    long ip_prefix = 192168179;
    long startIP_address = 1;
    long endIP_address = 255;
    long addressesToScan = endIP_address - startIP_address+1;

    bool workToDo = true;

    struct hosts_struct hosts[addressesToScan];

    int variable = 8;
    while (workToDo)
    {
        // Thread ID
        pthread_t tid[addressesToScan];
        
        // Create Attributes
        pthread_attr_t attr;
        pthread_attr_init(&attr);

        for (int i = 1; i <= addressesToScan; i++)
        {
            pthread_create(&tid[i], &attr, scanForIP, &i);
            hosts[i].ip = i;

            //Setting a Thread name
            char buffer[20];
            snprintf(buffer, sizeof(buffer), "%C%i", "Thread-", i);
            printf(buffer);
            pthread_setname_np(tid[i],  buffer);
            //pthread_join(tid, NULL);
            //sleep(2);
        }

        for (int i = 1; i <= addressesToScan; i++)
        {
            
            // Wait until thread is done
            pthread_join(tid[i], NULL);
            
            printf("HostName: %d:%d %d \n", ip_prefix, hosts[i].ip, hosts[i].online);

        }
        



        workToDo = false;
    }
    


    

    return 0;
}

