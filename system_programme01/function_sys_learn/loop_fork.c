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
	int i;

	for(i = 0; i < 5; i++) {
		if(fork() == 0) {
			break;
		}
	}
	if(i == 5) {
		printf("I'm parent.\n'");
	} else {
		printf("I'm %dth child.\n", i+1);
	}

	return 0;
}

