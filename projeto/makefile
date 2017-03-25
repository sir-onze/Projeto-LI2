CFLAGS = -Wall -Wextra -pedantic -O2
OBJS = $(patsubst %.c, %.o, $(wildcard *.c))
EXEC = projeto

instalar:$(OBJS)
	gcc $(CFLAGS) -o $(EXEC) $(OBJS)

	sudo cp $(EXEC) /usr/lib/cgi-bin

limpar:
	rm $(EXEC) *.o