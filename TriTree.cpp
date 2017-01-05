#include <iostream>
#include <cstdlib>
#include<cstdio>
#include "TriTree.h"
using namespace std;

/*
For Program 2, you will implement Ternary Search 3-ary Tree, which is a simple extension 
of a Binary Search Tree, with the following differences:
•	Each node stores 0, 1, or 2 elements.
•	Each node is the parent of 0, 1, 2, or 3 subtrees (left, center, and right).
•	Nodes in the left subtree are less than the 1st stored element, nodes in the center 
subtree fall between the node’s two stored elements, and nodes in the right subtree are 
greater than the two stored elements.
Your code should implement the same exact interface as the Binary Search Tree. Design a 
set of tests to see whether the runtime of BST and T3ST implementations differ 
significantly for large numbers of stored nodes. Log2N should grow faster than Log3N, 
right? Your tests should try to uncover “how big” a difference that makes, in an 
implementation.
Turn in your code, comprehensive test programs that demonstrate that your BST and T3ST 
implementations work properly, and a 1 page report that concisely (a) states the problem 
that you set out to solve for Program 2, (b) describes the tests that you ran, and (c) 
draws conclusions about the runtime difference between your BST and T3ST implementations.
*/

template <class T>
TriTree<T>::TriTree(){
	//default constructor
	root = NULL;
	checkMin = false;
	checkMax = false;
};

template <class T>
TriTree<T>::TriTree(const T & input){
	//value constructor
	root = NULL;
	checkMin = false;
	checkMax = false;
};

template <class T>
TriTree<T>::TriTree(const TriTree & bst){
	//copy constructor
	root = NULL;
	checkMin = false;
	checkMax = false;
};


//use bool to represent if initial node is empty

template <class T>
bool TriTree<T>::insert(const T & input){
	bool retVal = auxFuncInsert(root,input);
	return retVal;
		
};


template <class T>
bool TriTree<T>::auxFuncInsert(Node * child, const T & input) {

	Node * newNode = new Node;
	newNode->data = input;
	newNode->right = NULL;
	newNode->left = NULL;
	newNode->middle = NULL;

	if (root == NULL) { //if the root is null, we need to create the tree
		root = newNode;
		checkMin = true;
		return true;

	}
	else { //root is not null

		if ((checkMax == false) && (checkMin == true)) {
		
			if(input > child->data){
				child->data2 = input;
				checkMax = true;
				child->rMax = true;
				return true;
					
			}else{
			
				child->data2 = child->data;
				child->data = input;
				checkMax = true;
				child->rMax = true;
				return true;
			}
		}
		
		else if (input == child->data) { // reject duplicates
			return false;
		}

		else if (input < child->data) {    //go through the left subtree

			if (child->left == NULL) {
				child->left = newNode; //insert node
				return true;

			}
			
			else if (child->left->rMax == false) { //create left

				if (input > child->left->data) {
				
					child->left->data2 = input;
					child->left->rMax = true;
					return true;

				}
				else if(input < child->left->data) {
				
					child->left->data2 = child->left->data;
					child->left->data = input;
					child->left->rMax = true;
					return true;
				}

			}
			else {
				return auxFuncInsert(child->left, input);
			}
		}

		else if (input < child->data2) { //create middle

			if (child->middle == NULL) {
				child->middle = newNode;
				return true;

			}
			else if (child->middle->rMax == false) {
				if (input > child->middle->data) {
					child->middle->data2 = input;
					child->middle->rMax = true;
					return true;

				}
				else {
					child->middle->data2 = child->middle->data;
					child->middle->data = input;
					child->middle->rMax = true;
					return true;
				}

			}
			else {
				return auxFuncInsert(child->middle, input);
			}
		}

		else if (input > child->data2) { //go through the right subtree
			if (child->right == NULL) {
				child->right = newNode; //insert node
				return true;

			}
			else if (child->right->rMax == false) {
				if (input > child->right->data) {
					child->right->data2 = input;
					child->right->rMax = true;
					return true;

				}
				else {
					child->right->data2 = child->right->data;
					child->right->data = input;
					child->right->rMax = true;					
					return true;
				}
			}
			else {
				return auxFuncInsert(child->right, input);
			}
		}
		}

		return false;	//default return value		
	};

template <class T>
bool TriTree<T>::remove(const T &input) {
	bool retVal = auxFuncRemove(root, NULL, input);
	return retVal;
};

template <class T>
typename TriTree<T>::Node* TriTree<T>::findPre(Node* child) {
	while (child->right != NULL){
		child = child->right;
	}
	return child; //returns predecessor
};

template <class T>
typename TriTree<T>::Node* TriTree<T>::findSuc(Node* child) {
	while (child->left != NULL){
		child = child->left;
	}
	return child; //returns successor
};

template <class T>
void TriTree<T>::removeNode(Node * child, Node * parent, Node * temp){
	//delete
	//if input to be deleted is smaller than roots data then in left subtree
	if (temp->data <= child->data) {
		if(parent->left != NULL && parent->left->data == temp->data){
			parent->left = NULL;
			delete temp;
		}
		else if(parent->middle != NULL && parent->middle->data == temp->data){
			parent->middle = NULL;
			delete temp;
		}
		else if(parent->right != NULL && parent->right->data == temp->data){
			parent->right = NULL;
			delete temp;
		}
		else{
			if(child->left != NULL){
				return removeNode(child->left, child, temp);
			}
		}
	}

	//if input to be deleted is less than roots data2 then in middle subtree
	else if(temp->data <= child->data2 && temp->data >= child->data){
	
		if(parent->left != NULL && parent->left->data == temp->data){
			parent->left = NULL;
			delete temp;
		}
		else if(parent->middle != NULL && parent->middle->data == temp->data){
			parent->middle = NULL;
			delete temp;
		}
		else if(parent->right != NULL && parent->right->data == temp->data){
			parent->right = NULL;
			delete temp;
		}
		else{
			if(child->middle != NULL){
				return removeNode(child->middle, child, temp);
			}
		}	
	}
	
	//if input to be deleted is is greater than roots data2 then in right subtree
	else if(temp->data >= child->data2) {
	
		if(parent->left != NULL && parent->left->data == temp->data){
			parent->left = NULL;
			delete temp;
		}
		else if(parent->middle != NULL && parent->middle->data == temp->data){
			parent->middle = NULL;
			delete temp;
		}
		else if(parent->right != NULL && parent->right->data == temp->data){
			parent->right = NULL;
			delete temp;
		}
		else{
			if(child->right != NULL){
				return removeNode(child->right, child, temp);
			}
		}	
	}	
};

/*------------------------------------	cases ----------------------------------------------
1) No children remove (data) and there is (data2): remove (data) and shift (data2) over
2) No children remove (data) and there is no (data2): remove (data) and set node to null
3) No children remove (data2): remove (data2)

4) One child on the right remove (data) and there is (data2): remove (data) and shift (data2) over and 
	move (child->right->data) to (data2)
5) One child on the left remove (data) and there is (data2): remove (data) and move
	(child->left->data2) over to (data). 
6) One child in the middle remove (data) and there is (data2): remove (data) and move
	(child->middle->data) to (data).
7) One child on the right remove (data2): remove (data2) and move (child->right->data) to 
	(data2). 
8) One child on the left remove (data2): shift (data) to (data2) and move 
	(child->left->data2) to (data) 
9) One child in the middle remove (data2): move (child->middle->data2) to (data2)
---------------------------------------------------------------------------------------------*/

template <class T>
bool TriTree<T>::auxFuncRemove(Node * child, Node * parent, const T & input) {

	//base case
	if (child == NULL) {	
		return false;
	}

	//if input to be deleted is smaller than roots data then in left subtree
	else if (input < child->data) {
		if(child->left != NULL){
			return auxFuncRemove(child->left, child, input);
		}else{
			return false;
		}
	}
	
	//if input to be deleted is less than roots data2 then in middle subtree
	else if(child->rMax == true && input < child->data2 && input > child->data){
		if(child->middle != NULL){
			return auxFuncRemove(child->middle, child, input);
		}else{
			return false;
		}
	}
	
	//if input to be deleted is is greater than roots data2 then in right subtree
	else if(child->rMax == true && input > child->data2) {
		if(child->right != 	NULL){
			return auxFuncRemove(child->right, child, input);
		}else{
			return false;
		}
	}
	
	//if input is same as root data or data2, then it should be deleted 
	else{
		if(input == child->data){
			//the node has no children
			if(child->left == NULL && child->right == NULL && child->middle == NULL){
				if(child->rMax == true){
					//remove (data) and shift (data2) over
					child->data = child->data2;
					child->rMax = false;
					return true;
					
				}else{
					//remove (child)
					if(parent->right != NULL && parent->right->data == child->data){
						parent->right = child->left;
						delete child;
						return true;
					}
					else if(parent->middle != NULL && parent->middle->data == child->data){
						parent->middle = child->left;
						delete child;
						return true;
					}
					else if(parent->left != NULL && parent->left->data == child->data){
						parent->left = child->left;
						delete child;
						return true;
					}
				}
			
			//the node has left child 
			}else if(child->left != NULL){	
				Node * temp;
				if(child != NULL){
					temp = findPre(child->left);
					if(temp->rMax == true){
						child->data = temp->data2;
						child->rMax = true;
						return auxFuncRemove(child->left, child, temp->data2);
						
					}else{
						child->data = temp->data;
						removeNode(child, child, temp);				
						return true;
					}
				}	
			}
			
			//the node has middle child
			else if(child->middle != NULL){	
				
				Node * temp;
				if(child != NULL){
					temp = findSuc(child->middle);
					child->data = temp->data;
					child->rMax = true;
					return auxFuncRemove(child->middle, child, temp->data);
				}
			}
			
			//the node has right child
			else if(child->right != NULL){

				child->data = child->data2;
				child->rMax = false;
				Node * temp;
				
				if(child != NULL){
					temp = findSuc(child->right);
					child->data2 = temp->data;
					child->rMax = true;

					return auxFuncRemove(child->right, child, temp->data);
				}
			}
		}
		
		//if we are trying to remove data2
		else if(input == child->data2){
			
			//the node has no children
			if(child->left == NULL && child->middle == NULL && child->right == NULL){
				child->rMax = false;
				return true;
			}
			
			//the node has a right child
			else if(child->right != NULL){
				Node * temp;
				if(child != NULL){
					temp = findSuc(child->right);
					child->data2 = temp->data;
					child->rMax = true;

					return auxFuncRemove(child->right, child, temp->data);
				}
			}
			
			//the node has a middle child
			else if(child->middle != NULL){
				Node * temp;
				if(child != NULL){
					temp = findPre(child->middle);
					if(temp->rMax == true){
						child->data2 = temp->data2;
						child->rMax = true;
						return auxFuncRemove(child->middle, child, temp->data2);
					}else{
						child->data2 = temp->data;
						//delete
						removeNode(child, child, temp);						
						return true;
					}
				}
			}
			
			//the node has a left child
			else if(child->left != NULL){
				child->data2 = child->data;
				Node * temp;
				if(child != NULL){
					temp = findPre(child->left);
					if(temp->rMax == true){
						child->data = temp->data2;
						child->rMax = true;
						return auxFuncRemove(child->left, child, temp->data2);
					}else{
						child->data = temp->data;
						//delete
						removeNode(child, child, temp);						
						return true;
					}
				}
			}
		}
	}
	return false;		
};

template <class T>
bool TriTree<T>::find(const T &data) {
	bool retVal = auxFuncFind(root, data);
	return retVal;		
};

template <class T>
bool TriTree<T>::auxFuncFind(Node * child, const T & input){  //done

	if(child != NULL){ //check 1
		if (input == child->data){
        		return true;
        
		}else if(input == child->data2){
				return true;
				
		}else if (input < child->data) {
			if (child->left == NULL){
				return false;
		    
			}else{
				return auxFuncFind(child->left, input);
			}	
	
		}else if (input < child->data2){
			if (child->middle == NULL){
		    		return false;
		    
			}
			else{
				return auxFuncFind(child->middle, input);
			}
			
		}else if (input > child->data2) {
	
			if (child->right == NULL){
		    		return false;   
			}else{
				return auxFuncFind(child->right, input);
			}
		}
	}else{
		return false;
	}
	return false;
};

template <class T>
void TriTree<T>::auxfuncDisplay(Node * point){  //done
	if(root != NULL){
	
		if(point->left != NULL){
			auxfuncDisplay(point->left);
		}
		
		if(point->data){
			cout << point->data << " D1" << endl;
		}
		
		if(point->middle != NULL){
			auxfuncDisplay(point->middle);
		}
		
		if(point->rMax == true){
			cout << point->data2 << " D2" << endl;
		}
		
		if(point->right != NULL){
			auxfuncDisplay(point->right);
		}
	}
};

template <class T>
void TriTree<T>::display(){
	auxfuncDisplay(root);
};

template <class T>
TriTree<T>::~TriTree(){
	//destructor
	delete root;
}
