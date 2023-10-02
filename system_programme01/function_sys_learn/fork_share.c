/**
* File Name: fork_share.c
* Auther: Jichang
* Create Time: 2023年10月02日 星期一 11时34分34秒
* 进程共享测试
*/
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

int var = 100;

int main(int argc, char *argv[]) {
	pid_t pid;
	pid = fork();

	if(pid == -1) {
		perror("fork error.\n");
		exit(1);
	} else if(pid > 0) {
		var = 288;
		printf("parent, var=%d.\n", var);
		printf("I'm parent pid:%d, getppid:%d.\n", getpid(), getppid());
	} else if(pid == 0) {
		var = 200;
		printf("I'm child pid:%d, ppid:%d.\n", getpid(), getppid());
	}

	printf("-----finish------\n");
	return 0;
}

