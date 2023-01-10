CC = gcc
CFLAGS = -I./inc/
DEPS = Server.h
OBJ = src/Server.o

%o: %c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
Server: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) -lpthread

all:

clean:
	rm -rf *.o Server src/*.o
