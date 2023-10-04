/**
* File Name: ls_R.c
* Auther: Jichang
* Create Time: 2023年09月28日 星期四 18时57分05秒
* 实现目录的递归调用显示路径下所有的文件
* 
*/
#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>

#define PATH_LEN 256

void isFile(char *name);

/* 回调函数，被调用即为目录 */
void fetchdir(const char *dir, void (*fn)(char *)) {
	char name[PATH_LEN];
	struct dirent *sdp;
	DIR *dp;

	if((dp = opendir(dir)) == NULL) {
		/* 打开文件失败 */
		fprintf(stderr, "fetchdir: can't open %s'\n", dir);
		return;
	}
	/* 读取目录项 */
	while((sdp = readdir(dp)) != NULL) {
		if(strcmp(sdp->d_name, ".") == 0 || strcmp(sdp->d_name, "..") == 0) {
			/* 防止出现无限递归 */
			continue;
		}
		if(strlen(dir) + strlen(sdp->d_name) + 2 > sizeof(name)) {
			fprintf(stderr, "fetchdir: name %s %s too long\n", dir, sdp->d_name);
		} else {
			sprintf(name, "%s/%s", dir, sdp->d_name);
			(*fn)(name);
		}
	}
	closedir(dp);
}


/* 处理目录或者文件 */
void isFile(char *name) {
	struct stat sbuf;

	if(stat(name, &sbuf) == -1) {
		/* 文件名无效 */
		fprintf(stderr, "isfile: can't access %s\n'", name);
		exit(1);
	}

	if((sbuf.st_mode & S_IFMT) == S_IFDIR) {
		/* 判定是否为目录 */
		fetchdir(name, isFile); //回调函数
	}
	/* 不是目录，则是普通文件，直接打印文件名 */
	printf("%8ld %s\n", sbuf.st_size, name);
}


int main(int argc, char *argv[]) {
	if(argc == 1) {
		// 如果没有传入文件路径，直接设置当前文件路径
		isFile(".");
	} else {
		while(--argc > 0) {
			/* 可以一次查询多个目录 */
			/* 循环调用处理各个命令行传入的目录 */
			isFile(*++argv);
		}
	}

	return 0;
}

