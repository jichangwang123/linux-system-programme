/**
* File Name: zoom_test.c
* Auther: Jichang
* Create Time: 2023年10月03日 星期二 11时38分28秒
* 子进程回收
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>

int main() {
	pid_t pid, wpid;
	int status;

	pid = fork();

	if(pid == 0) {
		printf("--child, my id is:%d, going to sleep 10s\n", getpid());
		sleep(10);

		printf("--child die--\n");

		return 73;//返回一个特殊值
	} else if(pid > 0) {
		// 如果子进程未终止，父进程阻塞
		// wpid = wait(NULL); //不关系子进程终止原因
		wpid = wait(&status);  //回收子进程

		if(wpid == -1) {
			perror("wait error\n");
			exit(1);
		}

		if(WIFEXITED(status)) {
			// 如果为真，说明子进程正常终止
			printf("child exit with %d\n", WEXITSTATUS(status));	
		}

		if(WIFSIGNALED(status)) {
			// 如果为真，说明子进程被信号终止
			// 即异常终止
			printf("child kill with signal %d\n", WTERMSIG(status));
		}
		printf("--parent wait finish:%d\n", wpid);
	} else {
		perror("fork");
		return 1;
	}

	return 0;
}

