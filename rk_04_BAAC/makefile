CC = gcc
CFLAGS = -std=c99 -Wall -Werror -pedantic

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

.PHONY: clean

build: $(OBJS)
	$(CC) $(OBJS) -o app.exe

run: app.exe
    ./$<

%.o: %.c
	$(CC) -c $<

clean:
    rm -f *.o *.exe
