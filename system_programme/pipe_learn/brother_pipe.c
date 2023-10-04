/**
* File Name: brother_pipe.c
* Auther: Jichang
* Create Time: 2023年10月04日 星期三 16时37分25秒
* 兄弟进程间通信
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/wait.h>
#include<string.h>

void sys_err(const char *str) {
	perror(str);
	exit(1);
}

int main(int argc, char *argv[]) {
	int fd[2];
	pid_t pid;
	int ret, i;

	ret = pipe(fd); //申请管道
	if(ret == -1) {
		sys_err("pipe error.");
	}

	/* 循环创建2个子进程 */
	for(i = 0; i < 2; i++) {
		pid = fork();
		if(pid == -1) {
			sys_err("fork error.");
		}
		if(pid == 0) {
			break;
		}
	}

	if(i == 2) {
		/* 两个进程 */
		close(fd[0]);
		close(fd[1]); //关闭父进程的读端和写端
		wait(NULL);
		wait(NULL);
	} else if(i == 0) {
		//兄进程
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execlp("ls", "ls", NULL);
		sys_err("execlp ls error.");
	} else if(i == 1) {
		//弟进程
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		execlp("wc", "wc", "-l", NULL);
		sys_err("execlp wc error.");
	}

	return 0;
}

