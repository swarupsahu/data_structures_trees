#include "stdio.h"
#include <stdbool.h>
#include <stdlib.h>

struct Node{
	int value;
	struct Node * left;
	struct Node * right;
	struct Node * parent;
};

/* PRE:  Take as input an integer value we want to make a node of.
// POST: Makes a Node leaf on the heap. Return a pointer to that new
//       Node. */
struct Node * makeNode(int v){
	struct Node * nodePtr;

	nodePtr = (struct Node *) malloc (sizeof(struct Node));

	nodePtr->value = v;
	nodePtr->left  = NULL;
	nodePtr->right = NULL;
	nodePtr->parent = NULL;

	return nodePtr;
}

/* PRE:  Take as input a pointer to a Node on the heap.
// POST: Print the value of the Node. */
void printNode(struct Node * nodePtr){
	printf("%d ", nodePtr->value);
}

/* PRE:  Take as input a pointer to a Node on the heap.
// POST: Returns true if this node does not have a left and
//       does not have a right, false otherwise.
// POINTS: 5 */
int isLeaf(struct Node * nodePtr){
	int leaf = false;

	if (nodePtr != NULL){
		if ((nodePtr->left == NULL) && (nodePtr->right == NULL)){
			leaf = true;
		}
	}
	return leaf;
}

/* PRE:  Take as input a pointer to a Node on the heap.
// POST: Print the whole tree starting at the root nodePtr,
//       printing the left half, then this node's value, then
//       the right half.
// NOTE: This must be done using recursion.
// POINTS: 10 */
void printTree(struct Node * nodePtr){
	if (nodePtr != NULL){
		if (nodePtr->left != NULL){
			printTree(nodePtr->left);
		}
		
		printNode(nodePtr);
		
		if (nodePtr->right != NULL){
			printTree(nodePtr->right);
		}

	}
}


/* PRE:  Take as input a pointer to a Node on the heap.
//       Also take as input the value we want to add to the tree.
// POST: Adds value to the tree starting at nodePtr. If value is 
//       less than or equal to nodePtr->value, add value
//       down the left side of the tree. Otherwise, add value 
//       down the right side of the tree.
// NOTE: This must be done using recursion.
// POINTS: 20 */
void addValue(struct Node * nodePtr, int value){
	if (nodePtr == NULL){
		/*This node is NULL, lets add value here*/
		nodePtr = makeNode(value);
	}

	if (value <= nodePtr->value){
		if (nodePtr->left == NULL){
			nodePtr->left = makeNode(value);
			nodePtr->left->parent = nodePtr;
		}else{
			addValue(nodePtr->left,value);
		}
	}else{
		if (nodePtr->right == NULL){
			nodePtr->right = makeNode(value);
			nodePtr->right->parent = nodePtr;
		}else{
			addValue(nodePtr->right,value);
		}
	}
}

/* PRE:  Take as input a pointer to a Node on the heap.
//       Take as input the value you are searching for to delete.
// POST: Removes the lowest instance of the value found in the tree. 
//       When removing a node in the middle of the tree, properly connects
//       the tree following the criteria of our binary tree (left side of 
//       the tree is <= root, right side is > root).
//       Returns true if a value was removed, false otherwise.
// NOTE: This must be done using recursion.
// POINTS: 40 */
int removeValue(struct Node ** nodePtr, int value){

	struct Node * newPtr = * nodePtr; 

	/* Base case */
	if (newPtr == NULL) { 
		return (false); 
	}
	
		if (newPtr->value > value) {

		removeValue(&newPtr->left, value); 

		} else if (newPtr->value < value) {

		removeValue(&newPtr->right, value); 

		} else {

			if (newPtr->left == NULL && newPtr->right != NULL) { 

			struct Node *temp = newPtr->right;
			newPtr->value = temp->value;
			temp->parent->right = NULL;
			temp->parent = NULL; 
			free(temp); 
			return (true); 

			} else if (newPtr->right == NULL && newPtr->left != NULL) { 

			struct Node *temp = newPtr->left;
			newPtr->value = temp->value;
			temp->parent->left = NULL;
			temp->parent = NULL; 
			free(temp); 
			return (true); 

			} else if (isLeaf(newPtr)) {

				if (newPtr->parent->value >= newPtr->value) {
					newPtr->parent->left = NULL;
				} else if (newPtr->parent->value < newPtr->value) { 
					newPtr->parent->right = NULL;
				}
				free(newPtr);
				return(true);

			} else { 
			 
				if (newPtr->left->value == newPtr->value) {
					struct Node *temp = newPtr->left;
					printf ("Temp Value: %d\n", temp->value);
					newPtr->left = temp->left;
					temp->left->parent = newPtr;
					temp->parent = NULL;
					return(true);
				} else { 

				struct Node *temp = newPtr->right; 

				/* Go into the right side of the node and pick the smallest value.*/
				while (temp->left != NULL) {
					temp = temp->left; 
				}

				/* Replace the deleted node with temp's content.*/
				newPtr->value = temp->value;

				/* If the temp pointer is a node */
				if (isLeaf(temp)) { 
					if (temp->parent->value >= temp->value) {
						temp->parent->left = temp->left; 
					}
				}

				/* If the left pointer of temp has contents then point it to the replaced node */				
				else if (temp->left != NULL) {
					temp->parent->left = NULL;
				} 
				
				/*If the left is blank then the right pointer should now be connected to the parent.*/
				else if (temp->left == NULL){	
					temp->parent->right = temp->right;
				}	

				return(true);	
			}
		}
	}
}

/* PRE:  Take as input a pointer to a Node on the heap.
// POST: Delete every node of the tree, including root.
// NOTE: This must be done using recursion.
// POINTS: 15 */
void deleteTree(struct Node * nodePtr){
	if (nodePtr->left != NULL){
		deleteTree(nodePtr->left);
	}
	if (nodePtr->right != NULL){
		deleteTree(nodePtr->right);
	}
	free(nodePtr);
	nodePtr = NULL;
}