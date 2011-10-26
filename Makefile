CC=g++
CFLAGS=-I.
LIBS=-lboost_system -lboost_thread -lboost_filesystem

patcher:
	$(CC) file_manager.cpp patch_list.cpp downloader.cpp main.cpp $(LIBS) -o patcher

clean:
	rm -rf *o patcher patch.txt