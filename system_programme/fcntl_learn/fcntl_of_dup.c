/**
* File Name: fcntl_of_dup.c
* Auther: Jichang
* Create Time: 2023年10月01日 星期日 11时25分08秒
* fcntl实现dup
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	int fd1 = open(argv[1], O_RDWR);
	printf("fd1 = %d\n", fd1);

	// 0被占用，fcntl使用文件描述符表中可用的最小文件描述符返回
	int newfd = fcntl(fd1, F_DUPFD, 0);
	printf("newfd = %d\n", newfd);

	// 指定 7,未被占用，会返回 >=7 的文件描述符
	// 假如被占用，则返回大于7的
	int newfd2 = fcntl(fd1, F_DUPFD, 7);
	printf("newfd2 = %d\n", newfd2);

	int ret = write(newfd2, "YYYYY", 7); //写到文件中
	printf("ret = %d\n", ret);

	return 0;
}

