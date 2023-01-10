CC = gcc
CFLAGS = -I./include/
DEPS = Client_2.h
OBJ = source/Client_main_2.o source/Client_func_2.o

%o: %c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
Client_2: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

all:

clean:
	rm -rf *.o Client_2 src/*.o
