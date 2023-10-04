/**
* File Name: lseek_get_size.c
* Auther: Jichang
* Create Time: 2023年09月27日 星期三 08时23分00秒
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[]) {
	int fd = open(argv[1], O_RDWR);
	if(fd == -1) {
		perror("open error.\n");
		exit(1);
	}
	int length = lseek(fd, 111, SEEK_END);
	printf("file size: %d.\n", length);

	write(fd, "\0", 1);

	close(fd);
	return 0;
}

