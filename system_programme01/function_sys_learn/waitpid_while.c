/**
* File Name: waitpid_while.c
* Auther: Jichang
* Create Time: 2023年10月03日 星期 二 14时05分12秒
* waitpid回收多个子进程
*/
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
	int i;
	pid_t wpid, pid; 

	for(i = 0; i < 5; i++) {
		pid = fork();
		if(pid == 0) {
			// 循环期间，子进程不fork
			break;
		}
	}
	if(i == 5) {
		while((wpid = waitpid(-1, NULL, 0))) {
			printf("wait child %d\n", wpid);
		}
	} else {
		sleep(i);
		printf("I am %dth child, pid:%d\n", i+1, getpid());
	}
	return 0;
}

