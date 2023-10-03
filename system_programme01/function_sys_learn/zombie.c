/**
* File Name: zombie.c
* Auther: Jichang
* Create Time: 2023年10月03日 星期二 11时23分00秒
* 僵尸进程测试
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
	pid_t pid;
	pid = fork();

	if(pid == 0) {
		printf("--child, parent is:%d, going to sleep 10s\n", getppid());
		sleep(10);
		printf("--child die--");
	} else if(pid > 0) {
		while(1) {
			printf("I am parent, pid:%d, my son:%d\n", getpid(), pid);
			sleep(1);
		}
	} else {
		perror("fork");
		return 1;
	}

	return 0;
}
