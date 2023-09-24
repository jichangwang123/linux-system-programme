/**
* File Name: fcntl_test01.c
* Auther: Jichang
* Create Time: 2023年09月24日 星期日 14时22分47秒
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>

#define MSG_TRY "try again.\n"

int main() {
	char buf[10];
	int flags, n;
	// 有返回值
	flags = fcntl(STDIN_FILENO, F_GETFL); //获取stdin属性信息
	if(flags == -1) {
		perror("fcntl error.\n");
		exit(1);
	}
	flags |= O_NONBLOCK;
	int ret = fcntl(STDIN_FILENO, F_SETFL, flags); // 设置文件状态
	if(ret == -1) {
		perror("fcntl error.\n");
		exit(1);
	}
tryagain:
	n = read(STDIN_FILENO, buf, 10);
	if(n < 0) {
		if(errno != EAGAIN) {
			perror("read /dev/tty.\n");
			exit(1);
		}		
		sleep(3);
		write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
		goto tryagain;
	}
	write(STDOUT_FILENO, buf, n);
	return 0;
}
