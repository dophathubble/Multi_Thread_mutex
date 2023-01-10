CC = gcc
CFLAGS = -I./include/
DEPS = Client_1.h
OBJ = source/Client_main_1.o source/Client_func_1.o

%o: %c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
Client_1: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

all:

clean:
	rm -rf *.o Client_1 src/*.o
