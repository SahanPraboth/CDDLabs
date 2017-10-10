

CC=g++
CFLAGS= -std=c++11 -pthread
Cfiles= Semaphore.cpp signal.cpp

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

ALL: $(Cfiles)
	$(CC) -o signal $(Cfiles) $(CFLAGS)


#this is customary and just deletes all .o files
CLEAN:
	rm *.oCC=g++
