CC = gcc
CFLAGS = -I./include/
DEPS = Server.h
OBJ = source/Server.o

%o: %c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
Server: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) -lpthread

all:

clean:
	rm -rf *.o Server src/*.o
