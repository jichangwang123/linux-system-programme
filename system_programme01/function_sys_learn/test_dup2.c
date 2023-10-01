/**
* File Name: test_dup2.c
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

	int fdret = dup2(fd1, fd2);
	printf("fdret = %d\n", fdret);

	return 0;
}
