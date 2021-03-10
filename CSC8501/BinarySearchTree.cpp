#include <iostream>
#include <stdlib.h>
using namespace std;
struct node 
{ 
	int value; 
	struct node* left; 
	struct node* right; 
};

struct node* root = nullptr;
int COUNT = 10;
int NUM = 10;

// implement the functions described by these headers

void insert_integer(struct node** tree, int value)
{
	node** nptr;
	*nptr = (value <= (*tree)->value ? (*tree)->left : (*tree)->right);
	
	if (*nptr == nullptr)
	{
		*nptr = new node;
		(*nptr)->value = value;
	}
	else
		insert_integer(nptr, value);
}

void print_tree(struct node* tree, int space)
{
	// Base case  
	if (root == NULL)
		return;

	// Increase distance between levels  
	space += COUNT;

	// Process right child first  
	print_tree(tree->right, space);

	// Print current node after space  
	// count  
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << tree->value << "\n";

	// Process left child  
	print_tree(tree->left, space);
}

void terminate_tree(struct node* tree);

int most_common_integer(struct node* tree);

int largest_integer(struct node* tree);

int summ_of_all_integers(struct node* tree);

// Main function

//int main() {
//
//	// call your implemented functions here to test the binary search tree
//
//
//
//	for (int i = 0; i < NUM; i++)
//	{
//		int newNodeVal = rand() % 100;
//		cout << newNodeVal << endl;
//		insert_integer(&root, newNodeVal);
//	}
//
//	print_tree(root, 0);
//	return 0;
//}