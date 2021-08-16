#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
int main()
{
int sd,nd,n,len,reult,n1;
struct sockaddr_in seraddress, cliaddr;
sd=socket(AF_INET, SOCK_STREAM,0);
seraddress.sin_family=AF_INET;
seraddress.sin_addr.s_addr=INADDR_ANY;
seraddress.sin_port=htons(10200);
len=sizeof(seraddress);
connect(sd,(struct sockaddr*)&seraddress,len);
char buff[100];
int a , b;
char op;
printf("Enter two integers to perform the operation \n");
scanf(" %d %d",&a,&b);
printf("Enter the operator:");
scanf(" %c",&op);buff[0]=a;
buff[1]=b;
buff[2]=op;
buff[3]='\0';
write(sd,&buff,100);
char buf1[100];
n1=read(sd,buf1,100);
printf("%d %c %d : %d\n",a,op,b, *buf1);
}