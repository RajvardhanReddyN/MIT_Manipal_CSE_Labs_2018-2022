#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<strings.h> //for bzero
#include<arpa/inet.h>
#include<string.h>
#define PORT 5050
#define ERROR -1
#define MAX 1024
int main(int argc, char const *argv[])
{
int sockfd, clientfd, data_len;
struct sockaddr_in server, client;
char buffer[MAX];
pid_t pid;
//Step 1: Create a socket
if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == ERROR){
perror("server socket: ");
exit(-1);
}
//Step 2: Assign the socket ip and port
server.sin_family = AF_INET;
server.sin_port = htons(PORT);
server.sin_addr.s_addr = INADDR_ANY;
//Clear the structurebzero(&server.sin_zero, 8);
//Step 3: bind the socket to the ip address
if((bind(sockfd, (struct sockaddr*) &server, sizeof(struct sockaddr_in))) == ERROR){
perror("sbind: ");
exit(-1);
}
//Step 4: The listen() function converts an unconnected socket into a passive socket
if((listen(sockfd, 5)) == ERROR){
perror("listen: ");
exit(-1);
}
int len = sizeof(struct sockaddr_in);
//Infinite loop to keep the server from closing
while(1){
//Step 5: accept request
//The accept() is used to retrieve a connect request and convert that into a request.
clientfd = accept(sockfd, (struct sockaddr*) &client, &len);
pid = fork();
if(pid == 0){
//Child process begins here
//child closes listening socket
close(sockfd);
while(1)
{
//Step 6: process the request here
bzero(buffer, MAX);
data_len = read(clientfd, buffer, sizeof(buffer));
if(strncmp("exit", buffer, 4) == 0){
printf("[-]Disconnected from %s : %d\n\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
break;
}
printf("Message from client: %s\n", buffer);
}
close(clientfd);
exit(0); //Terminate child process
}
}return 0;
}