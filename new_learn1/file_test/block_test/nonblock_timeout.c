/**
* File Name: nonblock_readtty.c
* Auther: Jichang
* Create Time: 2023年09月21日 星期四 11时24分04秒
*
* 非阻塞方式read
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

#define MSG_TRY "try again\n"
#define MSG_TIMEOUT "time out\n"

int main() {
	char buf[10];
	int fd, n, i;

	fd = open("/dev/tty", O_RDONLY | O_NONBLOCK); //打开终端
	if(fd < 0) {
		perror("open /dev/tty.\n");
		exit(1);
	}
	printf("open /dev/tty... ok.%d\n", fd);


	for(i = 0; i < 5; i++) {	
		//循环五次
		n = read(fd, buf, 10);
		if(n > 0) {
			break;		//读取到了东西
		}
		if(errno != EAGAIN) {
			perror("read /dev/tty.\n");
			exit(1);
		} else {
			write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
			sleep(2);
		}
	}
	//超时
	if(i == 5) {
		write(STDOUT_FILENO,MSG_TIMEOUT, strlen(MSG_TIMEOUT));
	} else {
		write(STDOUT_FILENO, buf, n);
	}
	
	close(fd);

	return 0;
}

