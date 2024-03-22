#include <stdio.h>
#include <unistd.h>

int main(){

printf("The beginning of the program\n");
pid_t pid,pid2=fork();
printf("I AM RUNNING %d, MY PARENT is %d pid1 %d pid2 %d \n",getpid(),getppid(),pid,pid2);
return 0;
}


