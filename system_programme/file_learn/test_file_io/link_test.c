/**
* File Name: link_test.c
* Auther: Jichang
* Create Time: 2023年09月27日 星期三 14时45分57秒
* link函数的有关测试
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
	link(argv[1], argv[2]);
	unlink(argv[1]);

	return 0;
}

