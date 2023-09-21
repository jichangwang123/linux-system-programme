src=$(wildcard ./src/*.c) 	# 选中所有.c
objs=$(patsubst ./src/%.c, ./obj/%.o, $(src)) #替换为所有.c
inc_path=./inc  #头文件目录


# 生成警告信息
myArgs= -Wall -g

# 目标
ALL:main

# 生成链接文件
main:$(objs)
	gcc $^ -o $@ $(myArgs)

# 模式规则(静态)
$(objs):./obj/%.o:./src/%.c
	gcc -c $< -o $@ $(myArgs) -I $(inc_path) #后面表示添加的头文件：

# 删除所有生成的文件
clean:
	-rm -rf $(objs) main

.PHONY:clean ALL
