/**
* File Name: open.c
* Auther: Jichang
* Create Time: 2023年09月19日 星期二 15时17分40秒
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

int main() {
	//文件操作	
	int fd = open("./open.c", O_RDONLY | O_CREAT | O_TRUNC, 0777); //rw-r--r--
	printf("fd = %d, errno = %d:%s\n", fd, errno, strerror(errno));
	close(fd);
	return 0;
}
