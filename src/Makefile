CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: door_struct stack_test

door_struct: 
	$(CC) $(CFLAGS) dmanager_module.c -o ../build/Quest_1

stack_test: 
	$(CC) $(CFLAGS) stack.c stack_test.c -o ../build/Quest_3

clean:
	rm -f *.o 
	rm -f ../build/Quest*
