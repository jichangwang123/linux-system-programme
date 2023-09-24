/**
* File Name: fcntl_test01.c
* Auther: Jichang
* Create Time: 2023年09月24日 星期日 14时22分47秒
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MSG_TRY "try again.\n"

int main() {
	char buf[10];
	int flags, n;

	flags = fcntl(STDIN_FILENO, F_GETFL); //获取stdin属性信息
	if(flags == -1) {
		perror("fcntl error.\n");
		exit(1);
	}
	flags |= O_NONBLOCK;
	if(ret == -1) {
		perror("fcntl error.\n");
		exit(1);
	}
tryagain:
	n = read(STDIN_FILENO, buf, 10);
	if(n < 0) {
		
	}
}
