/**
* File Name: test01_fork.c
* Auther: Jichang
* Create Time: 2023年10月02日 星期一 09时07分29秒
* 关于fork()创建子进程
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[]) 
{
	printf("before fork-1\n");
	printf("before fork-2\n");
	printf("before fork-3\n");
	printf("before fork-4\n");
	
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("fork error.\n");
		exit(1);
	}
	else if(pid == 0)
	{
		printf("child is created.\n");
	}
	else if(pid > 0)
	{
		printf("parrnt peocess: mychild is %d.\n", pid);
	}
	printf("===================end.\n");

	return 0;
}

