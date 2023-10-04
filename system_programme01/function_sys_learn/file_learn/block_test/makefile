CC = gcc
src = $(wildcard *.c)
objs = $(patsubst %.c, %, $(src))

ALL: $(objs)

%:%.c
	$(CC) $< -o $@

clean:
	-rm -rf $(objs)

.PHONY:clean ALL
