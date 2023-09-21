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

int main() {
	char buf[10];
	int fd, n;

	fd = open("/dev/tty", O_RDONLY | O_NONBLOCK); //打开终端
	if(fd < 0) {
		perror("open /dev/tty.\n");
		exit(1);
	}

tryagain:
	n = read(fd, buf, 10);
	if(n < 0) {
		if(errno != EAGAIN) {
			perror("read /dev/tty.\n");
			exit(1);
		} else {
			write(STDOUT_FILENO, "try again\n", strlen("try again\n"));
			sleep(2);
			goto tryagain;
		}
	}
	
	write(STDOUT_FILENO, buf, n);
	close(fd);

	return 0;
}

