CC=g++
CFLAGS=-I.
LIBS=-lboost_system -lboost_thread

patcher:
	$(CC) main.cpp $(LIBS) -o patcher