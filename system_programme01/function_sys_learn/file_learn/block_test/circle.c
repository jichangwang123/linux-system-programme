/**
* File Name: circle.c
* Auther: Jichang
* Create Time: 2023年09月21日 星期四 12时37分10秒
*/
#include<stdio.h>

#define PI 3.14

int main() {
	double s;
	double radius;
	scanf("%lf", &radius);
	if(radius < 0) {
		printf("error");
	} else {
		printf("%.2lf", (radius * radius * PI));
	}

	return 0;
}
