#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>


#define MAX_DATA 256
#define PORT 5432

int main() {
    struct sockaddr_in saddr_in;
    char send_buff[MAX_DATA];
    char recv_buff[MAX_DATA];
    int sock_fd;
    char *host = "127.0.0.1";

    bzero(&saddr_in, sizeof(saddr_in));
    saddr_in.sin_family = AF_INET;
    saddr_in.sin_addr.s_addr=inet_addr(host);
    saddr_in.sin_port = htons(PORT);
    
    
}