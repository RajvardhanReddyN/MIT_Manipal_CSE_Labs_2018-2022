#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 2

void getNextAlphabet (char *a)
{
	char *n = (char *)calloc(2, sizeof(char));
	n[1] = '\0';
	if (*a == 'Z')
		n[0] = 'a';
	else if (*a == 'z')
		n[0] = 'A';
	else
		n[0] = *a + 1;
	*a = *n;
}

int main (int argc, const char * argv [])
{
	int shmid = shmget(IPC_PRIVATE, SIZE, S_IRUSR | S_IWUSR);
	if(shmid==-1)
	{
		fprintf(stderr, "shmget failed\n");
		exit(EXIT_FAILURE);
	}

	char *shared_memory = (char *)shmat(shmid, NULL, 0);
	if(shared_memory==(void*)-1)
	{
		fprintf(stderr, "shmat failed\n");
		exit(EXIT_FAILURE);
	}
	*shared_memory = '\0';

	printf("Enter an alphabet: ");
	scanf("%c", shared_memory);

	pid_t pid = fork();
	if (pid == 0) //child process
	{
		while (*shared_memory == '\0');
		getNextAlphabet(shared_memory);
		exit(0);
	}
	else //parent process
	{
		printf("%s -> ", shared_memory);
		wait(NULL);
		printf("%s\n", shared_memory);
	}

	if(shmdt(shared_memory)==-1)
	{
		fprintf(stderr, "shmdt failed\n");
		exit(EXIT_FAILURE);
	}
	if(shmctl(shmid, IPC_RMID, NULL)==-1)
	{
		fprintf(stderr, "IPC_RMID failed\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
