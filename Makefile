CC = gcc
CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror
VFLAGS = --leak-check=full --show-reachable=yes --track-origins=yes
GFLAGS = -tui
OBJFILES = pruebas_abb_alumno.o testing.o main.o abb.o pila.o
EXEC = pruebas

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<
$(EXEC): $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) -o $(EXEC)
all: $(EXEC)
run: all clear
	./$(EXEC)
clear:
	clear
valgrind: all clear
	valgrind $(VFLAGS) ./$(EXEC)
gdb: all clear
	gdb $(GFLAGS) ./$(EXEC)
free: $(OBJFILES)
	rm -f pruebas *.o