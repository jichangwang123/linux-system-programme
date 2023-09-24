/**
* File Name: error_01.c
* Auther: Jichang
* Create Time: 2023年09月24日 星期日 17时03分10秒
* 简单的使用系统调用的例子
*/
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[]) {
	char const * const str = "Hello world.\n";
	write(STDOUT_FILENO, str, strlen(str));

	return 0;
}
