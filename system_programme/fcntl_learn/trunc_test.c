/**
* File Name: trunc_test.c
* Auther: Jichang
* Create Time: 2023年09月27日 星期三 08时40分27秒
*/
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[]) {
	//open()/lseek，用lseek来拓展大小
	int ret = truncate("lseek.txt", 999);
	printf("ret = %d.\n", ret);

	return 0;
}
