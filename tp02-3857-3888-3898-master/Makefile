TARGET=tp

# compiler
CC=gcc
CCO=clang
# warnings
WARN=-Wall


CCFLAGS=$(WARN)

SRC= tp.c main.c

all:
	$(CC) -o $(TARGET) $(SRC) $(CCFLAGS) -lm

run:
	./$(TARGET)

clear:
	rm $(TARGET)