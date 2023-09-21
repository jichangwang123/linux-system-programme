src=$(wildcard *.c) 	# 选中所有.c
obj=$(patsubst %.c, %.o, $(src)) #替换为所有.c

# 生成警告信息
myArgs= -Wall -g

# 目标
ALL:main

# 生成链接文件
main:$(obj)
	gcc $^ -o $@ $(myArgs)

# 模式规则(静态)
$(obj):%.o:%.c
	gcc -c $< -o $@ $(myArgs)

# 删除所有生成的文件
clean:
	-rm -rf $(obj) main

.PHONY:clean ALL
