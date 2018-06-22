PROG = executavel
CC = g++
CPPFLAGS = -Wall -pedantic -std=c++11 -I./include
LDFLAGS = -L./lib 
BUILD = ./build/
BIN = ./bin/
OBJS = $(BUILD)main.o $(BUILD)iemanja.o 
$(PROG):$(OBJS)
	$(CC) $(LDFLAGS) -o $(BIN)$(PROG) $(OBJS)
./build/main.o:
	$(CC) $(CPPFLAGS) -c src/main.cpp -o $(BUILD)main.o
./build/iemanja.o:./include/iemanja.h
	$(CC) $(CPPFLAGS) -c src/iemanja.cpp -o $(BUILD)iemanja.o
clean:
	rm -f core $(BIN)$(PROG) $(OBJS) 