/*
* File Name: 03_ls-wc-l.c
* Auther: Jichang
* Create Time: 2023年10月04日 星期三 10时33分41秒
* 管道写入不同情况时
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>

/* 报错函数 */
void sys_err(const char *str) {
	perror(str);
	exit(1);
}

int main(int argc, char *argv[]) {
	int fd[2];
	int ret = pipe(fd);
	if(ret == -1) {
		//创建管道失败
		sys_err("pip error.");
	}

	pid_t pid = fork();
	if(pid == -1) {
		//创建子进程失败
		sys_err("fork error.");
	} else if(pid > 0) {
		//子进程, wc -l
		//关闭写端
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		execlp("wc", "wc", "-l", NULL);
	} else if(pid == 0) {
		//父进程，执行ls
		//父进程写入，需要关闭读的一端
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);//重定向输出
		execlp("ls", "ls", NULL);
		sys_err("execlp error.");
	}

	return 0;
}

