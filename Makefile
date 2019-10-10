TARGET=main

# all .cpp files in this directory are my sources
SOURCES=$(wildcard *.cpp)

OBJS=$(SOURCES:.cpp=.o)

INC_DIR=../include
CC=g++
CFLAGS= -c -pedantic -Wall -Werror -Wconversion -ansi -g -I$(INC_DIR)
CXXFLAGS= $(CFLAGS)
LDFLAGS=-g
$(TARGET): $(OBJS)
include .depends

.PHONY: clean run gdb


.depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) > .depends

clean:
	rm -f $(OBJS) $(TARGET) .depends

run: $(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

