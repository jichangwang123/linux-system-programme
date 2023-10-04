/**
* File Name: gdb_01.c
* Auther: Jichang
* Create Time: 2023年09月17日 星期日 14时28分14秒
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10

//初始化数组
void init_arr(int *arr, int len) {
	int i = 0;
	for(i = 0; i < len; i++) {
		arr[i] = rand() % 20 + 1;
	}
}

//选择排序
void select_sort(int *arr, int len) {
	int i, j, k, tmp;
	for(i = 0; i < len - 1; i++) {
		k = i;
		for(j = i+1; j < len; j++) {
			if(arr[k] > arr[j]) {
				k = j;
			}
		}
		if(i != k) {
			tmp = arr[i];
			arr[i] = arr[k];
			arr[k] = tmp;
		}
	}
}

//打印数组
void print_arr(int *arr, int len) {
	int i;
	for(i = 0; i < len; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}

int main() {
	int arr[N];
	char *p = "hello world.\n";

	srand(time(NULL));

	init_arr(arr, N);
	print_arr(arr, N);

	select_sort(arr, N);
	printf("after sort:\n");
	print_arr(arr, N);

	return 0;
}
