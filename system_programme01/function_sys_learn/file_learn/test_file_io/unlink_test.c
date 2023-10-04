/**
* File Name: unlink_text.c
* Auther: Jichang
* Create Time: 2023年09月27日 星期三 14时52分43秒
*/
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int aegc, char *argv[]) {
	int fd, ret;
	char *p = "test of unlink.\n";
	char *p2 = "after write something.\n";

	fd = open("temp.txt", O_RDWR|O_CREAT|O_TRUNC, 0644);
	if(fd < 0) {
		perror("open temp error.\n");
		exit(1);
	}

	ret = write(fd, p, strlen(p));
	if(ret == -1) {
		perror("------write error------\n");
	}
	printf("hi! I'm printf.\n");

	ret = write(fd, p2, strlen(p2));
	if(ret == -1) {
		perror("-----write error-------\n");
	}
	printf("Enter anykey continue.\n");
	getchar();
	close(fd);
	
	ret = unlink("temp.txt");//具备了被释放的条件
	if(ret < 0) {
		perror("unlink error.\n");
		exit(1);
	}

	return 0;
}
