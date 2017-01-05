FLAGS = -Wall -std=c++11

all: Lab6

Lab6:  Lab6.o BST.o
	g++ $(FLAGS) Lab6.o BST.o -o Lab6

BST.o: BST.cpp BST.h
	g++ $(FLAGS) -c BST.cpp -o BST.o

Lab6.o: Lab6.cpp BST.h
	g++ $(FLAGS) -c Lab6.cpp -o Lab6.o

clean: 
	rm -f *.o Lab6