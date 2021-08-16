#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
// printf("Q1 program executing\n");
int status;
pid_t pid;
pid = fork();

if(pid == -1)
{
printf("Error creating child process\n");
}

else if(pid == 0)
{
printf("I'm the child process\n");
exit(0);
}

else
{
wait(&status);
printf("I'm the parent process\n");
printf("Child returned status : %d\n",status);
}
return 0;
}