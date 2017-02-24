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
    
    if ((sock_fd = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Error with socket\n");
        exit(1);
    }

    if (connect(sock_fd, (struct sockaddr *) &saddr_in, sizeof(saddr_in)) < 0) {
        perror("");
        fprintf(stderr, "Error with connect\n");
        close(sock_fd);
        exit(1);
    }

    while (1) {
        bzero(send_buff, sizeof(send_buff));
        bzero(recv_buff, sizeof(recv_buff));
        fgets(send_buff, sizeof(send_buff), stdin);
        send_buff[MAX_DATA-1] = '\0';
        write(sock_fd, send_buff, strlen(send_buff)+1);
        read(sock_fd, recv_buff,sizeof(recv_buff));
        printf("%s", recv_buff);

    }
    return 0;
}