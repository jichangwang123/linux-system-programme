/**
* File Name: main.c
* Auther: Jichang
* Create Time: 2023年09月18日 星期一 22时28分36秒
*/
#include"head.h"

int main() {
	int a = 10, b = 5;
	printf("%d + %d = %d\n", a, b, add(a,b));
	printf("%d - %d = %d\n", a, b, sub(a,b));
	printf("%d * %d = %d\n", a, b, multi(a,b));
	printf("%d / %d = %d\n", a, b, divi(a,b));
	return 0;
}
