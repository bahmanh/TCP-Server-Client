#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>

#define MAX_DATA = 256
#define PORT = 3228

int main() {
    
    char buff[MAX_DATA];
    struct sockaddr_in saddr_in;
    int sock_fd, conn_fd;

    bzero(&saddr_in, sizeof(saddr_in));
    saddr_in.sin_family = AF_INET;
    saddr_in.s_addr = INADDR_ANY;
    saddr_in.sin_port = htons(PORT);

    if ((s = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Error with socket\n");
    }

    
}