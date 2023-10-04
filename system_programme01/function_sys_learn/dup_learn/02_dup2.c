/**
* File Name: 02_dup2.c
* Auther: Jichang
* Create Time: 2023年10月01日 星期日 09时57分05秒
*/
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[]) 
{
	int fd1 = open(argv[1], O_RDWR);
	int fd2 = open(argv[2], O_RDWR);

	int fdret = dup2(fd1, fd2); // 返回新文件描述符 fd2
	printf("fdret = %d\n", fdret);

	int ret = write(fd2, "1234567", 7);  //写入fd1指向的文件
	printf("ret = %d\n", ret);
	
	/* 在屏幕输出的内容输出到文件中，重定向到文件 */
	dup2(fd1, STDOUT_FILENO);

	printf("-----------888\n");

	return 0;
}
