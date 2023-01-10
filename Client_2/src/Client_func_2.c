#include <Client_2.h>

void Client_func()
{
    int sockfd, n;
    char Buff[100]="2: Hello Server";
    int Buff1;
    struct sockaddr_in address; 
    int result;

    sockfd = socket( AF_INET, SOCK_STREAM, 0 );

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr( "127.0.1.3" );
    address.sin_port = htons(PORT);

    result = connect( sockfd, (struct sockaddr*)&address, sizeof( address ) );
        if ( result == -1 ) 
        {
            perror( "\nOops: client1 problem" );
            exit( 1 );
        }
    while (1)
    {
        write( sockfd, Buff, sizeof(Buff));
        n = read ( sockfd, &Buff1, sizeof(Buff1));
        if (n > 0) 
        {
            printf("Message from Server: %d\n", Buff1);
        }
    }
}