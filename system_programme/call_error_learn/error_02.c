/**
* File Name: error_02.c
* Auther: Jichang
* Create Time: 2023年09月24日 星期日 17时06分32秒
*/
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>

int main(int argc, char *argv[]) {
	char const * const str = "Hello world\n";
	int rc = write(-1, str, strlen(str));
	if(rc < 0) {
		printf("write error, error code: %d.\n", errno);
	}
	return 0;
}
