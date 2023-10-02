CC = gcc
src = $(wildcard *.c)
objs = $(patsubst %.c, %, $(src))

myArgs = -Wall -g

ALL:$(objs)

%:%.c
	$(CC) $< -o $@ $(myArgs)

clean:
	-rm -rf $(objs)

.PHONY:clean ALL
