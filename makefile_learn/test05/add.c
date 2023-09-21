/**
* File Name: add.c
* Auther: Jichang
* Create Time: 2023年09月18日 星期一 22时33分44秒
*/
#include<stdio.h>

int add(int a, int b) {
	return a + b;
}

int main() {
	printf("2 + 3 = %d\n", add(2, 3));
	return 0;
}
