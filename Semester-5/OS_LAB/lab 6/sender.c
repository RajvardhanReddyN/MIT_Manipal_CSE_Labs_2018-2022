#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <errno.h>

#define SIZE 128

typedef struct message {
    long mtype;
    char c[SIZE];
}MESSAGE;

int main()
{
	int qt;
	MESSAGE msg;
	if((qt = msgget(1272, 0)) < 0)
	{ 
		perror("Error in msgget()");
		exit(EXIT_FAILURE);
	}
	printf("Enter the number: ");
	fgets(msg.c, SIZE, stdin);
	msg.mtype = 1;
	if(msgsnd(qt, &msg, sizeof(MESSAGE), 0) < 0)
	{
		perror("Error in msgsnd()");
		exit(1);
		}
	printf("Successfully sent.\n");
	return 0;
}