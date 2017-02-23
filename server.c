#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <strings.h>

#define MAX_DATA  256
#define PORT  3228
#define MAX_CONNECTIONS  5

int main() {
    
    char buff[MAX_DATA];
    struct sockaddr_in saddr_in;
    int sock_fd, conn_fd;
    int length;

    bzero(&saddr_in, sizeof(saddr_in));
    saddr_in.sin_family = AF_INET;
    saddr_in.sin_addr.s_addr = INADDR_ANY;
    saddr_in.sin_port = htons(PORT);

    if ((sock_fd = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Error with socket\n");
        exit(1);
    }

    if ((bind(sock_fd, (struct sockaddr *) &saddr_in, sizeof(saddr_in))) < 0) {
        fprintf(stderr, "Error with bind\n");
        exit(1);
    } 

    listen(sock_fd, MAX_CONNECTIONS);

    while(1) {
        bzero(&buff, sizeof(buff));
        
        if ((conn_fd = accept(sock_fd, (struct sockaddr *) &saddr_in, &length)) < 0) {
            fprintf(stderr, "Error with accept\n");
            exit(1);
        }

        while (length = recv(conn_fd, buff, sizeof(buff), 0)) {
            write(conn_fd, buff, length);
        }
        close(conn_fd);
    }

}