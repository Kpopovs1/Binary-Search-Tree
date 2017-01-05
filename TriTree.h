#ifndef _TriTree_H
#define _TriTree_H

#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>

class TriTree{
	
	public:
	
		struct Node {
 			Node * left;
			Node * middle;	
 			Node * right;			
 			T data;
 			T data2;
 			bool rMax = false;
 			
 			~Node(){
    			if(left) delete left;
    			if(right) delete right;
    			if(middle) delete middle;
			}
		};
	
		TriTree(); //default constructor
		TriTree(const T & input); //value constructor
		TriTree(const TriTree & bst); //copy constructor
		~TriTree();
				
		bool insert(const T &);
		bool remove(const T &);
		bool find(const T &);
		void display(); //inorder display
		void auxfuncDisplay(Node * ptr);
		bool auxFuncInsert(Node * child, const T & input);
		bool auxFuncFind(Node * child, const T & input);
		bool auxFuncRemove(Node * root, Node * parent, const T & input);
		void removeNode(Node* child, Node * parent, Node * temp);
		Node* findPre(Node* child);
		Node* findSuc(Node* child);
			
	private:
		Node * root;
		bool checkMax;
		bool checkMin;
};


#endif