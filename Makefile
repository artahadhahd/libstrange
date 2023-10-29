CC=gcc
C_STANDARD=c11 # recommended, you can use C99 >=
INCLUDE=-Iinclude
CWARNINGS=-Wall -Wextra -Wpedantic
CFLAGS=$(CWARNINGS) $(INCLUDE) -std=$(C_STANDARD)

all: bin/
	$(CC) $(CFLAGS) -c -o bin/strange.o src/strange.c

static: bin/strange.o
	ar rcs bin/libstrange.a bin/strange.o

shared: bin/strange.o
	$(CC) -shared -o bin/libstrange.so bin/strange.o

clean:
	@echo This deletes .o and .so files too. Enter Passphrase to confirm
	sudo rm -r bin/
