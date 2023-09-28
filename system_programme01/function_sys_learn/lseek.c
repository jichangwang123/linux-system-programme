/**
* File Name: lseek.c
* Auther: Jichang
* Create Time: 2023年09月24日 星期日 20时11分14秒
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main() {
	int fd, n;
	char msg[] = "It's a test for lseek.\n";
	char ch;

	fd = open("lseek.txt", O_RDWR | O_CREAT, 0644);
	if(fd < 0) {
		perror("open lseek.txt error.\n");
		exit(1);
	}
	write(fd, msg, strlen(msg)); // 使用fd对打开的文件进行写操作

	/* 修改文件读写指针位置，位于文件开头  */
	lseek(fd, 0, SEEK_SET);

	while((n == read(fd, &ch, 1))) {
		if(n < 0) {
			perror("read error.\n");
			exit(1);
		}
		/* 将文件内容直接读出，写出到屏幕 */
		write(STDOUT_FILENO, &ch, n);
	}
	close(fd);

	return 0;
}

