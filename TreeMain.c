#include "Tree.c"
#include <stdbool.h>
#include "stdio.h"
#include <stdlib.h>

/*-------------------------------------
//-       UNIT TESTS GO HERE          -
//-           POINTS:  10             -
//------------------------------------- */

int testingPrintTree1(){
	int succeed = false;
	struct Node * root = makeNode(5);

	printTree(root);
	printf("\n");

	free(root);
}

int testingPrintTree3(){
	int succeed = false;
	struct Node * root = makeNode(5);
	addValue(root,4);
	addValue(root,6);

	printTree(root);
	printf("\n");

	free(root->left);
	root->left = NULL;

	free(root->right);
	root->right = NULL;

	free(root);
}

int testingPrintTreeRepeatedValue(){
	int succeed = false;
	struct Node * root = makeNode(5);
	addValue(root,4);
	addValue(root,4);
	addValue(root,6);

	printTree(root);
	printf("\n");

	free(root->left->left);
	root->left->left = NULL;

	free(root->left);
	root->left = NULL;

	free(root->right);
	root->right = NULL;

	free(root);
}


int testAddingRoot(){
	int succeed = false;
	/* Create our Tree Root */
	struct Node * root = makeNode(5);
	if (root != NULL){
		if ((root->value == 5) && (root->left == NULL) && (root->right == NULL)){
			succeed = true;
		}
	}

	free(root);

	if (succeed == false){
		printf("Adding to Root Test Failed!\n");
	}

	return succeed;
}

int testAddingToLeftOfRoot(){
	int succeed = false;
	/* Create our Tree Root */
	struct Node * root = makeNode(5);
	addValue(root,4);
	if (root->left != NULL){
		if ((root->left->value == 4) && (root->left->parent == root)){
			succeed = true;
		}
	}

	free(root->left);
	root->left = NULL;
	free(root);

	if (succeed == false){
		printf("Adding to Left of Root Test Failed!\n");
	}

	return succeed;
}

int testAddingToRightOfRoot(){
	int succeed = false;
	/* Create our Tree Root */
	struct Node * root = makeNode(5);
	addValue(root,6);
	if (root->right != NULL){
		if ((root->right->value == 6) && (root->right->parent == root)){
			succeed = true;
		}
	}

	free(root->right);
	root->right = NULL;
	free(root);

	if (succeed == false){
		printf("Adding to Right of Root Test Failed!\n");
	}

	return succeed;
}

int testAddingToLeftOfNonRoot(){
	int succeed = false;
	/* Create our Tree Root */
	struct Node * root = makeNode(5);
	addValue(root,4);
	addValue(root,3);
	if (root->left != NULL){
		if ((root->left->value == 4) && (root->left->parent == root)){
			if (root->left->left != NULL){
				if ((root->left->left->value == 3) && (root->left->left->parent == root->left)){
					succeed = true;
				}
			}
		}
	}

	free(root->left->left);
	root->left->left = NULL;
	free(root->left);
	root->left = NULL;
	free(root);

	if (succeed == false){
		printf("Adding to Left of Left of Root Test Failed!\n");
	}

	return succeed;
}

int testAddingRepeatedValue(){
	int succeed = false;
	/* Create our Tree Root */
	struct Node * root = makeNode(5);
	addValue(root,5);
	addValue(root,5);
	if (root->left != NULL){
		if ((root->left->value == 5) && (root->left->parent == root)){
			if (root->left->left != NULL){
				if ((root->left->left->value == 5) && (root->left->left->parent == root->left)){
					succeed = true;
				}
			}
		}
	}

	free(root->left->left);
	root->left->left = NULL;
	free(root->left);
	root->left = NULL;
	free(root);

	if (succeed == false){
		printf("Adding to Left of Left of Root Reapted Value Test Failed!\n");
	}

	return succeed;
}

int testIsLeafRoot(){
	int succeed = false;

	struct Node * root = makeNode(5);

	if (isLeaf(root) == true){
		succeed = true;
	}

	free(root);

	if (succeed == false){
		printf("Checking root, which is a leaf, is a leaf failed!\n");
	}

	return succeed;
}

int testIsNotLeafRootLeft(){
	int succeed = false;

	struct Node * root = makeNode(5);
	addValue(root,4);

	if (isLeaf(root) == false){
		succeed = true;
	}

	free(root->left);
	root->left = NULL;
	free(root);

	if (succeed == false){
		printf("Checking root with a left child is a leaf failed!\n");
	}

	return succeed;
}

int testIsNotLeafRootRight(){
	int succeed = false;

	struct Node * root = makeNode(5);
	addValue(root,6);

	if (isLeaf(root) == false){
		succeed = true;
	}

	free(root->right);
	root->right = NULL;
	free(root);
	
	if (succeed == false){
		printf("Checking root with a right child is a leaf failed!\n");
	}

	return succeed;
}

int testIsLeafNonRoot(){
	int succeed = false;

	struct Node * root = makeNode(5);
	addValue(root,6);

	if (isLeaf(root->right) == true){
		succeed = true;
	}

	free(root->right);
	root->right = NULL;
	free(root);
	
	if (succeed == false){
		printf("Checking root->right with no children is a leaf failed!\n");
	}

	return succeed;
}

int testDeleteTree1(){
	struct Node * root = makeNode(5);

	deleteTree(root);
}

int testDeleteTreeLeft2(){
	struct Node * root = makeNode(5);
	addValue(root,4);

	deleteTree(root);
}

int testDeleteTreeRight2(){
	struct Node * root = makeNode(5);
	addValue(root,6);

	deleteTree(root);
}

int testDeleteTree3(){
	struct Node * root = makeNode(5);
	addValue(root,4);
	addValue(root,6);

	deleteTree(root);
}

int testDeleteTree4(){
	struct Node * root = makeNode(5);
	addValue(root,4);
	addValue(root,6);
	addValue(root,3);

	deleteTree(root);
}

int testRemovingLeafLeft(){
 	int succeed = false;

 	struct Node * root = makeNode(5);
 	addValue(root,4);
 	addValue(root,7);

 	if (root->left != NULL){
 		removeValue(&root,4);
 		if (root->left == NULL){
 			succeed = true;
 		}
 	}

 	free(root);

 	if (succeed == false){
 		printf("Removing Leaf Test Failed!\n");
 	}

 	return succeed;
}

int testRemovingLeafRight(){
 	int succeed = false;

 	struct Node * root = makeNode(5);
 	addValue(root,4);
 	addValue(root,7); 

 	if (root->right != NULL){
 		removeValue(&root,7);
 		if (root->right == NULL){
 			succeed = true;
 		}
 	}

	free(root);

 	if (succeed == false){
 		printf("Removing Leaf Test Failed!\n");
 	}

 	return succeed;
} 

int testRemovingLeafLeftWithOneChild(){
 	int succeed = false;

 	struct Node * root = makeNode(5);
 	addValue(root,4);
 	addValue(root,7); 
 	addValue(root,3);

 	if (root->left != NULL){
 		removeValue(&root,4);
 		if (root->left->value == 3){
 			succeed = true;
 		}
 	}

 	free(root);

 	if (succeed == false){
 		printf("Removing Leaf Test Failed!\n");
 	}

 	return succeed;
}

int testRemovingLeafRightWithOneChild(){
 	int succeed = false;

 	struct Node * root = makeNode(5);
 	addValue(root,4);
 	addValue(root,7); 
 	addValue(root,8);

 	if (root->right != NULL){
 		removeValue(&root,7);
 		if (root->right->value == 8){
 			succeed = true;
 		}
 	}

 	free(root);

 	if (succeed == false){
 		printf("Removing Leaf Test Failed!\n");
 	}

 	return succeed;
}

int testRemovingRootNode(){
 	int succeed = false;

 	struct Node * root = makeNode(5);
 	addValue(root,4);
 	addValue(root,7); 
 	addValue(root,6); 
 	addValue(root,8);

 	if (root != NULL){
 		removeValue(&root,5);
 		if (root->value == 6){
 			succeed = true;
 		}
 	}

 	free(root);

 	if (succeed == false){
 		printf("Removing Leaf Test Failed!\n");
 	}

 	return succeed;
}

int testRemovingNonExistingNode() { 
	int succeed = false;

 	struct Node * root = makeNode(5);
 	addValue(root,4);
 	addValue(root,7); 
 	addValue(root,6); 
 	addValue(root,8);

 	if (root != NULL){
 		succeed = removeValue(&root,10);
 		if (succeed == false) { 
 			return(true);
 		}
 	}

 	free(root);

 	if (succeed == true){
 		printf("Removing Leaf Test Failed!\n");
 		if (succeed == true) { 
 			return(false); 
 		}
 	}

 	return succeed;
}

int testRemovingRepeatedValue(){
 	int succeed = false;

 	struct Node * root = makeNode(5);
 	addValue(root,4);
 	addValue(root,7); 
 	addValue(root,6); 
 	addValue(root,8);
 	addValue(root,5);

 	if (root != NULL){
 		removeValue(&root,5);
 		if (root->value == 6){
 			succeed = true;
 		}
 	}

 	free(root);

 	if (succeed == false){
 		printf("Removing Leaf Test Failed!\n");
 	}

 	return succeed;
}

int testRemovingImmediateRepeatedValue(){
 	int succeed = false;

 	struct Node * root = makeNode(5);
 	addValue(root,4);
 	addValue(root,7); 
 	addValue(root,6); 
 	addValue(root,8);
 	addValue(root,5);
 	addValue(root,6);

 	if (root != NULL){
 		removeValue(&root,6);
 		if (root->right->left->value == 6){
 			succeed = true;
 		}
 	}

 	free(root);

 	if (succeed == false){
 		printf("Removing Leaf Test Failed!\n");
 	}

 	return succeed;
}

int testRemovingRootNodeWithOneLeftChild(){
 	int succeed = false;

 	struct Node * root = makeNode(5);
 	addValue(root,4);

 	if (root != NULL){
 		removeValue(&root,5);
 		if (root->value == 4){
 			succeed = true;
 		}
 	}

 	free(root);

 	if (succeed == false){
 		printf("Removing Leaf Test Failed!\n");
 	}

 	return succeed;
}

int testRemovingRootNodeWithOneRightChild(){
 	int succeed = false;

 	struct Node * root = makeNode(5);
 	addValue(root,7); 

 	if (root != NULL){
 		removeValue(&root,5);
 		if (root->value == 7){
 			succeed = true;
 		}
 	}

 	free(root);

 	if (succeed == false){
 		printf("Removing Leaf Test Failed!\n");
 	}

 	return succeed;
}
/*-------------------------------------
//-       MAIN CODE			          -
//-------------------------------------*/

int main(){

	int numTestCorrect = 0;
	int totalTests = 0;

	/* Test Printing the tree */
	printf("Size 1 Tree\n");
	testingPrintTree1();
	printf("Size 3 Tree\n");
	testingPrintTree3();
	printf("Size 4 Tree (with repeated)\n");
	testingPrintTreeRepeatedValue();

	/* Test Adding to the tree */
	numTestCorrect = numTestCorrect + testAddingRoot();
	totalTests++;
	numTestCorrect = numTestCorrect + testAddingToLeftOfRoot();
	totalTests++;
	numTestCorrect = numTestCorrect + testAddingToRightOfRoot();
	totalTests++;
	numTestCorrect = numTestCorrect + testAddingToLeftOfNonRoot();
	totalTests++;
	numTestCorrect = numTestCorrect + testAddingRepeatedValue();
	totalTests++;

	/* Test Removing from the tree */
	numTestCorrect = numTestCorrect + testRemovingLeafLeft();
	totalTests++;
	numTestCorrect = numTestCorrect + testRemovingLeafRight();
	totalTests++;
	numTestCorrect = numTestCorrect + testRemovingLeafLeftWithOneChild();
	totalTests++;
	numTestCorrect = numTestCorrect + testRemovingLeafRightWithOneChild();
	totalTests++;
	numTestCorrect = numTestCorrect + testRemovingRootNode();
	totalTests++;
	numTestCorrect = numTestCorrect + testRemovingNonExistingNode();
	totalTests++;
	numTestCorrect = numTestCorrect + testRemovingRepeatedValue();
	totalTests++;
	numTestCorrect = numTestCorrect + testRemovingImmediateRepeatedValue();
	totalTests++;
	numTestCorrect = numTestCorrect + testRemovingRootNodeWithOneLeftChild(); 
	totalTests++;
	numTestCorrect = numTestCorrect + testRemovingRootNodeWithOneRightChild(); 
	totalTests++;

	/* Test Deleting the tree */
	testDeleteTree1();
	testDeleteTreeLeft2();
	testDeleteTreeRight2();
	testDeleteTree3();
	testDeleteTree4();

	/* Test isLeaf */
	numTestCorrect = numTestCorrect + testIsLeafRoot();
	totalTests++;
	numTestCorrect = numTestCorrect + testIsNotLeafRootLeft();
	totalTests++;
	numTestCorrect = numTestCorrect + testIsNotLeafRootRight();
	totalTests++;
	numTestCorrect = numTestCorrect + testIsLeafNonRoot();
	totalTests++;

	printf("%d/%d successful tests.\n", numTestCorrect, totalTests);

	return 0;
}