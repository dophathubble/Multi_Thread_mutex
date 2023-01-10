
#include <Server.h>
int Buff1;
pthread_mutex_t a_mutex;

/*Create Thread 1 is a countup function and sent count value to Client*/
void* Communication_1(void* abc)
{   
    pthread_mutex_lock (&a_mutex);   
    int client_sockfd= (int *)abc;
    int server_sockfd, i;
    char Buff[100];

    server_sockfd = read (client_sockfd, Buff, sizeof(Buff));
    if (server_sockfd > 0) 
    {
        printf("\nMessage from Client %s\n", Buff );
    } 
    
    for (i=1; i <= 5; i++)
    {
        printf ("\nThread 1 countup: %d\n", ++Buff1);
        printf ("\nWaiting 1 second\n");
        sleep(1);
    
        write(client_sockfd, &Buff1, sizeof(Buff1));
    }
    pthread_mutex_unlock (&a_mutex);

    printf ("\nThread 1 completed !\n");
}

/*Create Thread 1 is a countdown function and sent count value to Client */
void* Communication_2(void* abc1)
{      
    int client_sockfd= (int *)abc1;
    int i;
  
    pthread_mutex_lock (&a_mutex);
    for (i=1; i <= 5; i++)
    {
        printf ("\nThread 2 countdown: %d\n", --Buff1);
        printf ("\nWaiting 1 second\n");
        sleep(1);
        
        write(client_sockfd, &Buff1, sizeof(Buff1));
    }
    pthread_mutex_unlock (&a_mutex);

    printf ("\nThread 2 completed !\n");
}

int main(int argc, char **argv[])
{       
    int server_sockfd, client_sockfd;
    int server_len, client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    pthread_t p_thread1; 
    pthread_t p_thread2; 

    server_sockfd = socket( AF_INET, SOCK_STREAM, 0 );

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr( "127.0.1.3" );
    server_address.sin_port = htons(PORT);

    bind( server_sockfd, (struct sockaddr *)&server_address, sizeof( server_address ) );

    listen( server_sockfd, 5 );
    printf( "\nWaiting for Connection...\n" );
    while (1)
    {
        client_sockfd = accept( server_sockfd, (struct sockaddr*)&client_address, &client_len );

        if (client_sockfd < 0) 
        { 
            printf("\nConnection Errors !!! \n"); 
            exit(0);
        }
        else printf("\nA New Client Has Connected !!! \n");

        pthread_mutex_init (&a_mutex, NULL);
        pthread_create (&p_thread1, NULL, &Communication_1,(void*)client_sockfd);
        pthread_create (&p_thread2, NULL, &Communication_2,(void*)client_sockfd);

    }
    return 0;
}
