#
# Makefile that builds btest and other helper programs for the CS:APP data lab
# 
CC = mingw32-g++.exe 
CFLAGS = -O -Wall -m32
LIBS = -lm

all: singly

singly: main.cpp slist.cpp slist.h airport.h
	$(CC) $(CFLAGS) $(LIBS) -o singly main.cpp slist.cpp

clean:
	rm -f *.o singly *~


