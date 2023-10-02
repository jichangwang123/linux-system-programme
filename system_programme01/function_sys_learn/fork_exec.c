/**
* File Name: fork_exec.c
* Auther: Jichang
* Create Time: 2023年10月02日 星期一 17时43分05秒
* 关于exec的一些测试
*/
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	pid_t pid = fork();
	if(pid == -1) {
		perror("fork error.\n");
		exit(1);
	} else if(pid == 0) {
		//子进程
		//NULL代表参数的结束
		/*execlp("ls", "-l", "-d", "-h", NULL); 错误写法*/
		//execlp("ls", "ls", "-l", "-h", NULL);
		execlp("date", "date", NULL);
		perror("exec error.\n");
		exit(1);
	} else if(pid > 0) {
		//父进程
		sleep(1);
		printf("I'm parent:%d\n", getpid());
	}
	return 0;
}
