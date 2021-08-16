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
int sd,nd,n,len,reult;
struct sockaddr_in seraddress, cliaddr;
sd=socket(AF_INET, SOCK_STREAM,0);
seraddress.sin_family=AF_INET;
seraddress.sin_addr.s_addr=INADDR_ANY;
seraddress.sin_port=htons(10200);
bind(sd,(struct sockaddr*)&seraddress,sizeof(seraddress));
listen(sd,2);
len = sizeof(cliaddr);
while(1)
{
char buff[100];
nd = accept(sd,(struct sockaddr*)&cliaddr,&len);
if (fork()==0)
{
close(sd);
// printf("Forked\n");
read(nd,buff,100);
printf("%d %d are the two received integers with operation to be performed : %c ",buff[0],buff[1],buff[2]);
char result[100];
// printf("%c\n",buff[2]);
switch(buff[2])
{
case '+': result[0] = (buff[0])+(buff[1]);
break;
case '-': result[0] = (buff[0])-(buff[1]);
break;
case '*': result[0] = (buff[0])*(buff[1]);
break;
case '/': result[0] = (buff[0])/(buff[1]);
break;
}
printf("\n the result is %d ", result[0]);
write(nd, result, 100);
close(nd);
exit(0);
}
}
}