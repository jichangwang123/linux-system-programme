/**
* File Name: fifo_r.c
* Auther: Jichang
* Create Time: 2023年10月05日 星期四 12时35分41秒
* mkfifo管道通信读操作
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

void sys_err(char *str) {
	perror(str);
	exit(1);
}

int main(int argc, char *argv[]){
	int fd, len;
	char buf[4096];
	
	if(argc < 2) {
		printf("./a.out fifoname\n");
		return -1;
	}

	fd = open(argv[1], O_RDONLY);
	if(fd < 0) {
		sys_err("open faild");
	}
	while(1) {
		len = read(fd, buf, sizeof(buf));
		write(STDOUT_FILENO, buf, len); //输出到屏幕
		sleep(3); //多个读端应增加秒数，放大效果
	}
	close(fd);

	return 0;
}

