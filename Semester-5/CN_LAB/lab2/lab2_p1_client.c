#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<strings.h> //for bzero
#include<arpa/inet.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>
#define PORT 5050
#define ERROR -1
#define MAX 1024
int main(int argc, char const *argv[])
{
int sockfd, len;
struct sockaddr_in remoteServer;
char buffer[MAX];
//Step 1: create a socket
if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == ERROR){
perror("server socket: ");
exit(-1);
}
//Step 2: Assign the socket ip and port
remoteServer.sin_family = AF_INET;
remoteServer.sin_port = htons(PORT);
remoteServer.sin_addr.s_addr = INADDR_ANY;
bzero(&remoteServer.sin_zero, 8);
//Step 3: connect to the remoteserver
if((connect(sockfd, (struct sockaddr*) &remoteServer, sizeof(struct sockaddr_in))) == ERROR){
perror("server socket: ");
exit(-1);
}
while(1)
{
printf("\nClient: ");fgets(buffer, MAX, stdin);
len = write(sockfd, buffer, strlen(buffer));
if(strncmp("exit", buffer, 4) == 0){
close(sockfd);
printf("[-]Disconnected from server.\n");
exit(1);
}
}
return 0;
}