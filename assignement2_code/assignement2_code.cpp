// Name : Keyur Bhavsar.
// Sudent id:8737391.
// Assignment 2.  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// structure defining a binary tree node.  Lower sorted values will go the the left, higher to the right.
struct nodeData {
	char name[30];				// character string of the data being stored in the node
	struct nodeData* left;		// pointer to the next node in the tree that is less than current node OR NULL if empty
	struct nodeData* right;		// pointer to the next node in the tree that is greater than current node OR NULL if empty
};

//here ,function definitions
void printBinaryTree(struct nodeData* node);
void addToBinaryTree(struct nodeData* newnode, const char* newString);

// data to be stored in tree.  In this case there is just a character string but this could have contained more

// replace inputData used for test put it in here and is created from Prog8130AssignDataCreator.exe 

const char* inputData[12] = {
		{ "soart"},
		{ "bhsof"},
		{ "utode"},
		{ "efrao"},
		{ "ltiyi"},
		{ "kdggx"},
		{ "xngqp"},
		{ "xkgfd"},
		{ "vlbak"},
		{ "sdxlh"},
		{ "txxri"},
		{ "hewow"}
};

int main()
{
	int i;
	struct nodeData* head = NULL;	// head of the binary tree
	head = (struct nodeData*)malloc(sizeof(struct nodeData));  //malloc the head
	head->left = head->right = NULL;
	// put all the data into the binary tree
	for (i = 0; i < 12; i++)
		addToBinaryTree(head, inputData[i]);
	printBinaryTree(head);

	return 0;
}


// FUNCTION      : addToBinaryTree
//
// DESCRIPTION   :
//   This function will store the data in newNode into a binary tree according to alphabetical order
//
// PARAMETERS    :
//   newString - the string that is to be stored in the binary tree in alphabetica order
//
// RETURNS       :
//   Nothing
void addToBinaryTree(struct nodeData* head, const char* newString)
{
	// add code to put items into binary tree in alphabetical order here
	// consider using strcmp library function to decide if a name is greater or less than

	if (head != NULL)
	{
		if (strcmp(newString, head->name) > 0)
		{
			if (head->right == NULL)
			{
				struct nodeData* temp = (struct nodeData*)malloc(sizeof(struct nodeData));
				temp->left = temp->right = NULL;
				strcpy_s(temp->name, newString);
				head->right = temp;

			}
			else
				addToBinaryTree(head->right, newString);
		}
		else
		{
			if (head->left == NULL)
			{
				struct nodeData* temp = (struct nodeData*)malloc(sizeof(struct nodeData));
				temp->left = temp->right = NULL;
				strcpy_s(temp->name, newString);
				head->left = temp;
			}
			else
				addToBinaryTree(head->left, newString);
		}

	}

}

// FUNCTION      : printBinaryTree
	//
	// DESCRIPTION   :
	//   This function will print the entire binary tree out.  You can choose to print
	//   it using recursion but more marks will be awarded if you do it non recursively.
	//
	// PARAMETERS    :
	//   None
	//
	// RETURNS       :
	//   Nothing

void printBinaryTree(struct nodeData* node)
{

	if (node == NULL)
		return;
	else
	{
		printBinaryTree(node->left);
		printf("%s \n", node->name);
		printBinaryTree(node->right);

	}

}