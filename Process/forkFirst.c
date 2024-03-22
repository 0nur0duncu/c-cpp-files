#include <stdio.h>
#include <unistd.h>

int main(){

printf("The beginning of the program\n");
pid_t pid = fork();
fork();
fork();
fork();

printf("I AM RUNNING %d, MY PARENT is %d\n",getpid(),getppid());
return 0;
}
