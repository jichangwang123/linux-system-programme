/**
* File Name: orphan.c
* Auther: Jichang
* Create Time: 2023年10月03日 星期二 11时14分01秒
* 孤儿进程
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
	pid_t pid;
	pid = fork();

	if(pid == 0) {
		while(1) {
			printf("I am child, my parent pid:%d\n", getppid());
			sleep(1);
		}
	} else if(pid > 0) {
		printf("I am parent, my pid is:%d\n", getpid());
		sleep(9);
		printf("--parent going to die--\n");
	} else {
		perror("fork error.");
		return 1;
	}
	return 0;
}

