/**
* File Name: mystat.c
* Auther: Jichang
* Create Time: 2023年09月27日 星期三 10时35分47秒
*/
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
	struct stat sbuf;

	int ret = lstat(argv[1], &sbuf);
	if(ret == -1) {
		perror("stat perror.\n");
		exit(1);
	}
	/* 打印文件大小 */
	printf("file size: %ld.\n", sbuf.st_size);  // 由于有偏移，输出用ld

	if(S_ISREG(sbuf.st_mode)) {
		printf("It is a regular.\n");
	} else if(S_ISDIR(sbuf.st_mode)) {
		printf("It is a dictionary.\n");
	} else if(S_ISFIFO(sbuf.st_mode)) {
		printf("It's a pipe.\n'");
	} else if(S_ISLNK(sbuf.st_mode)) {
		/* 软连接 */
		printf("It's a sym link.\n'");
	}
	return 0;
}
