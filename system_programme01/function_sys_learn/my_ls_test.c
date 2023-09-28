/**
* File Name: my_ls_test.c
* Auther: Jichang
* Create Time: 2023年09月28日 星期四 17时16分19秒
* 实现ls功能
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h> //注意加头文件

int main(int argc, char *argv[]) {
	DIR *dp; //一个文件流指针
	struct dirent *sdp;
	dp = opendir(argv[1]);
	if(dp == NULL) {
		perror("opendir error.\n");
		exit(1);
	}
	while((sdp = readdir(dp)) != NULL) {
		/* 去除显示目录中的 “.” */
		if((strcmp(sdp->d_name, ".") == 0) || (strcmp(sdp->d_name, "..") == 0)) {
			continue;
		}
		printf("%s\t", sdp->d_name);
	}
	printf("\n");

	closedir(dp);

	return 0;
}

