

#FLAGS = -Wall -std=c++11 -g

#all: Lab6

#Lab6:  Lab6.o BST.o
#	g++ $(FLAGS) Lab6.o BST.o -o Lab6

#BST.o: BST.cpp BST.h
#	g++ $(FLAGS) -c BST.cpp -o BST.o

#Lab6.o: Lab6.cpp BST.h
#	g++ $(FLAGS) -c Lab6.cpp -o Lab6.o

#clean: 
#	rm -f *.o Lab6

FLAGS = -Wall -std=c++11 -g

all: Lab6

Lab6:  Lab6.o TriTree.o
	g++ $(FLAGS) Lab6.o TriTree.o -o Lab6

TriTree.o: TriTree.cpp TriTree.h
	g++ $(FLAGS) -c TriTree.cpp -o TriTree.o

Lab6.o: Lab6.cpp TriTree.h
	g++ $(FLAGS) -c Lab6.cpp -o Lab6.o

clean: 
	rm -f *.o Lab6
