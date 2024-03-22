#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
	
	pid_t pid1,pid2;
	int status;
	pid2 = fork();
	printf("I AM RUNNING %d, MY PARENT is %d pid1 %d pid2 %d \n",getpid(),getppid(),pid1,pid2);
	if (pid2>0)
	{
		pid1 = wait(&status);
	    //if (WIFEXITED(status))
	
		printf("Child %d exited \n",pid1);
	}
	
	
}
