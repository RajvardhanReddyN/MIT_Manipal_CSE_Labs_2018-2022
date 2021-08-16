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

int isPalindrome(int n)
{
	int r = 0, num = n;
	while (n > 0)
	{
		r = r * 10 + n % 10;
		n = n / 10;
	}
	if (r == num)
		return 1;
	else
		return 0;
}

int main()
{
	int qt;
	MESSAGE msg;
	if ((qt = msgget(1272, IPC_CREAT | IPC_EXCL | 0600)) < 0)
	{
		perror("Error in msgget()");
		exit(EXIT_FAILURE);
	}
	printf("Message queue created.\n");
	if (msgrcv(qt, &msg, sizeof(MESSAGE), 0, 0) < 0)
	{
		perror("Error in msgrcv()");
		exit(EXIT_FAILURE);
	}
	printf("Successfully received number: %s\n", msg.c);

	int num = atoi(msg.c);
	if (isPalindrome(num))
		printf("The number is a palindrome\n");
	else
		printf("The number is not a palindrome\n");

	if(msgctl(qt, IPC_RMID, NULL)==-1)
	{
		fprintf(stderr, "IPC_RMID failed\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}