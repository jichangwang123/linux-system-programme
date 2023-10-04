/**
* File Name: waitpid_test.c
* Auther: Jichang
* Create Time: 2023年10月03日 星期 二 14时05分12秒
* waitpid函数测试
*/
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
	int i;
	pid_t wpid, pid, tmpid; //tmpid防止子进程pid覆盖 

	for(i = 0; i < 5; i++) {
		pid = fork();
		if(pid == 0) {
			// 循环期间，子进程不fork
			break;
		}
		if(i == 2) {
			tmpid = pid;
		}
	}
	if(i == 5) {
		sleep(5);
		// wait(NULL) 一次wait只能回收一个子进程
		// 回收任意子进程，没有结束的子进程，父进程直接返回0
		wpid = waitpid(tmpid, NULL, WNOHANG); //指定一个进程回收，不阻塞
		// wpid = waitpid(tmpid, NULL, 0); //制定一个进程回收，阻塞回收
		if(wpid == -1) {
			perror("waitpid error.");
			exit(1);
		}
		printf("I am parent, wait a child finish:%d \n", wpid);
	} else {
		sleep(i);
		printf("I am %dth child, pid:%d\n", i+1, getpid());
	}
	return 0;
}

