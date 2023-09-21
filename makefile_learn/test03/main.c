/**
* File Name: main.c
* Auther: Jichang
* Create Time: 2023年09月18日 星期一 22时28分36秒
*/
#include<stdio.h>

int add(int, int);
int sub(int, int);
int multi(int, int);
int divi(int, int);
int mode(int, int);  

int main() {
	int a = 10, b = 5;
	printf("%d + %d = %d\n", a, b, add(a,b));
	printf("%d - %d = %d\n", a, b, sub(a,b));
	printf("%d * %d = %d\n", a, b, multi(a,b));
	printf("%d / %d = %d\n", a, b, divi(a,b));
	printf("%d % %d = %d\n", a, b, mode(a,b));
	return 0;
}
