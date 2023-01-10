CC = gcc
CFLAGS = -I./inc/
DEPS = Client_2.h
OBJ = src/Client_main_2.o src/Client_func_2.o

%o: %c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
Client_2: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

all:

clean:
	rm -rf *.o Client_2 src/*.o
