#PROJETO LP1

PROG = ./bin/life_game
CC = g++
CPPFLAGS = -O0 -g -W -Wall -std=c++11 -pedantic
OBJS = main.o reader_file.o life.o
HEADER = ./include/header.h
SRC_DIR     = ./src/
BIN_DIR     = ./bin/

$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $(PROG)
	rm *.o

main.o: $(HEADER)
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)main.cpp
reader_file.o: $(HEADER)
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)reader_file.cpp
life.o: $(HEADER)
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)life.cpp
clean:
	rm -f $(PROG) 
