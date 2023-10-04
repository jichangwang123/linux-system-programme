/**
* File Name: double_test.c
* Auther: Jichang
* Create Time: 2023年09月17日 星期日 15时11分43秒
*/
#include<stdio.h>

int main() {
	double res = 0.0;
	printf("input:>");
	scanf("%lf", &res);

	printf("%.15lf\n", res);
	return 0;
}
