#ifndef _BST_H
#define _BST_H

#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>

class BST{
	
	public:
	
		struct Node {
 			Node * left;
 			Node * right;
 			T data;
		};
	
		BST(); //default constructor
		BST(const T & input); //value constructor
		BST(const BST & bst); //copy constructor
		
		bool insert(const T &);
		bool remove(const T &);
		bool find(const T &);
		void display(); //inorder display
		void auxfuncDisplay(Node * ptr);
		bool auxFuncInsert(Node * child, const T & input);
		bool auxFuncFind(Node * child, const T & input);
		bool auxFuncRemove(Node * root, Node * parent, const T & input);
		Node* findMin(Node* root);
			
	private:
		Node * root;
};

#endif