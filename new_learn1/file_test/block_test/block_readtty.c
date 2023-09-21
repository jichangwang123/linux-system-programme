/**
* File Name: block_readtty.c
* Auther: Jichang
* Create Time: 2023年09月21日 星期四 11时06分47秒
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main() {
	char buf[10];
	int n;

	n = read(STDIN_FILENO, buf, 10);
	if(n < 0) {
		perror("read STDIN_FILENO");
		exit(1);
	}
	write(STDOUT_FILENO, buf, n);

	return 0;
}
