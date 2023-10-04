/**
* File Name: exec_ps.c
* Auther: Jichang
* Create Time: 2023年10月02日 星期一 18时15分15秒
* 进程信息输出到文件中
*/
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	int fd;
	fd = open("ps.out", O_WRONLY|O_CREAT|O_TRUNC, 0644);
	if(fd < 0) {
		perror("open faild.\n");
		exit(1);
	} 
	dup2(fd, STDOUT_FILENO);
	execlp("ps", "ps", "aux", NULL);
	perror("exec error.\n");
	
	//close(fd);
	return 0;
}

