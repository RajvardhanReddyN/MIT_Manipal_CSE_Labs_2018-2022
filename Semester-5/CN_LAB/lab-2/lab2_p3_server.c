#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include<unistd.h>
#include<time.h>
#define MAX 80
#define PORT 8088
#define SA struct sockaddr
// Function designed for chat between client and server.
void servfunc(int sockfd)
{
char buff[MAX];
int n;
// infinite loop for chat
for (;;) {
bzero(buff, MAX);
// read the message from client and copy it in buffer
read(sockfd, buff, sizeof(buff));
// print buffer which contains the client contents
printf("From client: %s\t To client : ", buff);
// Read server message from keyboard in the buffer
n=0;
/* Define temporary variables */
time_t current_time;struct tm *local_time;
/* Retrieve the current time */
current_time = time(NULL);
/* Get the local time using the current time */
local_time = localtime(&current_time);
/* Display the local time */
char* bufft=asctime(local_time);
pid_t pid = getpid();
// printf("pid: %lun", pid);
// and send that buffer to client
write(sockfd, bufft, sizeof(buff));
// if msg contains "Exit" then server exit and session ended.
if (strncmp("quit", buff, 4) == 0) {
printf("Server Exit...\n");
break;
}
}
}
// Driver function
int main()
{
int sockfd, connfd, len;
struct sockaddr_in servaddr, cli;
// socket create and verification
sockfd = socket(AF_INET, SOCK_STREAM, 0);
if (sockfd == -1) {
printf("socket creation failed...\n");
exit(0);
}
else
printf("Socket successfully created..\n");
bzero(&servaddr, sizeof(servaddr));// assign IP, PORT
servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port = htons(PORT);
// Binding newly created socket to given IP and verification
if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
printf("socket bind failed...\n");
exit(0);
}
else
printf("Socket successfully binded..\n");
// Now server is ready to listen and verification
if ((listen(sockfd, 5)) != 0) {
printf("Listen failed...\n");
exit(0);
}
else
printf("Server listening..\n");
len = sizeof(cli);
// Accept the data packet from client and verification
connfd = accept(sockfd, (SA*)&cli, &len);
if (connfd < 0) {
printf("server acccept failed...\n");
exit(0);
}
else
printf("server acccept the client...\n");
int prt=ntohs (cli.sin_port);
printf("%d\n",prt);
// Function for chatting between client and server
servfunc(connfd);
// After sending exit message close the socket
close(sockfd);
}