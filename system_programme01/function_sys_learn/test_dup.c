/**
* File Name: test_dup.c
* Auther: Jichang
* Create Time: 2023年10月01日 星期日 09时15分35秒
* 系统函数学习: dup
*/
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int argc, char *argv[]) {
	int fd = open(argv[1], O_RDONLY);

	int newfd = dup(fd);

	printf("newfd = %d\n", newfd);

	return 0;
}

