/**
* File Name: 01_pipe.c
* Auther: Jichang
* Create Time: 2023年10月04日 星期三 10时33分41秒
* 管道创建测试
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
	int ret = 0;
	int fd[2];
	pid_t pid;
	char *str = "hello pipe\n";
	char buf[1024];

	ret = pipe(fd);
	if(ret == -1) {
		sys_err("pipe error.");
	}

	pid = fork();
	if(pid > 0) {
		close(fd[0]); //关闭读端
		write(fd[1], str, strlen(str));  //写数据
		sleep(1);//父进程睡眠1s
		close(fd[1]);
	} else if(pid == 0) {
		close(fd[1]); //子进程关闭写端
		ret = read(fd[0], buf, sizeof(buf));
		write(STDOUT_FILENO, buf, ret);
		close(fd[0]);
	}
	return 0;
}

