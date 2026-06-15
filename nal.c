#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){
	pid_t pid;

	printf("%d \n", getpid());

	for(int i = 0; i < 4; i++){pid = fork();}

	if(pid == 0){
		printf("pid = %d, pai pid = %d \n", getpid(), getppid());
		for(int i = 0; i < 4; i++){wait(NULL);}
	}

	printf("saindo pid = %d\n", getpid());

}
