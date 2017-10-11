#Garry Byrne 06/10/17

CC=g++
CFLAGS= -std=c++11 -pthread
CFiles= Semaphore.cpp signal.cpp

SIMPLE: $(CFiles)
		$(CC) $(CFLAGS) -o signal $(CFiles) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

Clean:
			 rm *.o
