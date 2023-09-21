src=$(wildcard *.c)
objs=$(patsubst %.c, %, $(src))

myArgs=-Wall -g

ALL:$(objs)

%:%.c
	gcc $< -o $@ $(myArgs)

clean:
	-rm -rf $(objs)

.PHONY:clean ALL
