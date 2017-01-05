#include <iostream>
#include <cstdlib>
#include<cstdio>
#include "BST.h"
using namespace std;

/*implement a templated Binary Search Tree and to measure the runtime of the 
implementation. BST class should support the following public member functions, with 
the usual definitions:
•	bool insert(const T &);
•	bool remove(const T &);
•	bool find(const T &) const;
•	void display() const; // inorder display
code should reject duplicate insertions. Design a set of tests to see whether 
implementation can show the difference between runtime complexity of balanced trees vs. 
unbalanced trees, for different problem sizes. To be very clear, do not implement a 
balanced binary tree! Recall and exploit the fact that insertion order influences the 
shape and characteristics of the tree. */

template <class T>
BST<T>::BST(){
	//default constructor
	root = NULL;
};

template <class T>
BST<T>::BST(const T & input){
	//value constructor
	root = NULL;
};

template <class T>
BST<T>::BST(const BST & bst){
	//copy constructor
	root = NULL;
};


//use bool to represent if initial node is empty

template <class T>
bool BST<T>::insert(const T & input){
	
	bool retVal = auxFuncInsert(root, input);
	
	return retVal;	
};

template <class T>
bool BST<T>::auxFuncInsert(Node * child, const T & input){

	Node * newNode = new Node;
	newNode->data = input;
	newNode->right = NULL;
	newNode->left = NULL;
		
	if(root == NULL){ //if the root is null, we need to create the tree
		root = newNode;
		return true;
		
	}else{ //root is not null
	 
		if(input == child->data){ // reject duplicates
			return false;
		}
		
		else if(input < child->data){    //go through the left subtree
			if(child->left == NULL){
				child->left = newNode; //insert node
				return true;
			}else{
				return auxFuncInsert(child->left, input);
			}
		}
		
		else if(input > child->data){ //go through the right subtree
			if(child->right == NULL){
				child->right = newNode; //insert node
				return true;
			}else{
				return auxFuncInsert(child->right,input);
			}
		}
	}
	
	return false;	//default return value	
};

template <class T>
bool BST<T>::remove(const T &input) {

	bool retVal = auxFuncRemove(root, root, input); //changed NULL to root

	return retVal;
};

template <class T>
typename BST<T>::Node* BST<T>::findMin(Node* root) {
	while (root->left != NULL)
		root = root->left;
	return root; //returns left most root
};


template <class T>
bool BST<T>::auxFuncRemove(Node * root, Node * parent, const T & input) {

	//base case
	if (root == NULL) {
		return false;
	}

	//if input to be deleted is smaller than roots data then in left subtree
	if (input < root->data) {
		return auxFuncRemove(root->left,root, input);
	}
	//if input to be deleted is greater than roots data then in right subtree
	else if(input > root->data) {
		
		return auxFuncRemove(root->right,root, input);

	}
	//if input is same as roots data, then node should be deleted 
	else {

		//cout << "here2" << endl;

		//node has only 1 child or no child
		if(parent != NULL && root != NULL && parent->left != NULL){
			if (root == parent->left && root->left == NULL) { //added an extra check
					//cout << "here3" << endl;

				parent->left = root->right;
				delete root;
				return true;
			}

		}
		else if (root == parent->right && root->right == NULL) { //here too
				//cout << "here4" << endl;

			parent->right = root->left;
			delete root;
			return true;

		}
		 //cout << "here5" << endl;
		//node with 2 children get the inorder successor (smallest in right sub tree)
		Node * temp;
		if(root->right != NULL && root != NULL){
			temp = findMin(root-> right);
			root->data = temp->data;
			return auxFuncRemove(root->right,root, temp->data);
		}

		/*// Copy the inorder successor's content to this node
		root->data = temp->data;

		// Delete the inorder successor		
		return auxFuncRemove(root->right,root, temp->data);*/
		
	}

	return false;
};

template <class T>
bool BST<T>::find(const T &data) {

	bool retVal = auxFuncFind(root, data);
	return retVal;	
	
};

template <class T>
bool BST<T>::auxFuncFind(Node * child, const T & input){

	if (input == child->data){
        return true;
        
	}else if (input < child->data) {
	
        if (child->left == NULL){
            return false;
            
		}else{
			return auxFuncFind(child->left, input);
	   	}
	   	
	}else if (input > child->data) {
	
		if (child->right == NULL){
            return false;
            
        }else{
			return auxFuncFind(child->right, input);
		}
	}
    return false;
};


template <class T>
void BST<T>::auxfuncDisplay(Node * point){

	if(root != NULL){
		if(point->left != NULL){
			auxfuncDisplay(point->left);
		}
		
		cout << point->data << endl;
		
		if(point->right != NULL){
			auxfuncDisplay(point->right);
		}
	}
};

template <class T>
void BST<T>::display(){
	//inorder display
	auxfuncDisplay(root);
};