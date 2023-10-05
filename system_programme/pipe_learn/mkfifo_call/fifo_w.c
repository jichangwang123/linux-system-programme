/**
* File Name: fifo_w.c
* Auther: Jichang
* Create Time: 2023年10月05日 星期四 12时36分10秒
* mkfifo写操作
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>

void sys_err(char *str) {
	perror(str);
	exit(-1);
}

int main(int argc, char *argv[]) {
	int fd, i;
	char buf[4096];

	if(argc < 2) {
		printf("Enter like this: ./a.out fifoname\n");
		return -1;
	}
	// 以写的方式打开文件
	fd = open(argv[1], O_WRONLY);
	if(fd < 0) {
		sys_err("open faild");
	}

	i = 0;
	while(1) {
		sprintf(buf, "hello mkfifo %d\n", i++);
		write(fd, buf, strlen(buf));
		sleep(1);
	}
	close(fd); //没机会执行

	return 0;
}


