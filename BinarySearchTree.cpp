#include "BinarySearchTree.h"
#include<iostream>
#include<fstream>
#pragma once
using namespace std;
// Destroying a Binary Search Tree releasing the memory occupied by all of its nodes
void destroyRecursive(Node* root);
Node* deepCopyTree(const Node *source);

// String to hold all ( IN || PRE || POST )ordersentences.
string order_sentence = " ";
// **Constructors ***
/**
* Default Constructor
* @type: Non-Parameterised Constructor
*/
BinarySearchTree::BinarySearchTree()
{

}

/**
* Constructor creating a binary search tree with an initial word to store
*
* std::string word: initial word to store
*
* @type: Parameterised Constructor
*/
BinarySearchTree::BinarySearchTree(std::string word)
{
	root = new Node;
	root->word = word;
	root->left = nullptr;
	root->right = nullptr;
}

/**
* Constructor creates a binary search tree by deep copying an existing binary search tree.
*
* const BinarySearchTree &rhs: A Binary Search Tree Adress
*
* @type: Parameterise Constructor
*/
BinarySearchTree::BinarySearchTree(const BinarySearchTree &rhs)
	:root(deepCopyTree(rhs.root))
{
}

/**
* Constructor creating a binary search tree from a vector of words.
*
* const std::vector<std::string> &words: vector of words
*
* @type: Parameterised Constructor
*/
BinarySearchTree::BinarySearchTree(const std::vector<std::string> &words)
{
	for (auto &w : words)
	{
		insert(w);
	}
}
/**
* Destructor for a binary search tree. Releases the memory occupied by all of its nodes.
*
* @type: Deconstructor
*/
BinarySearchTree::~BinarySearchTree()
{
	destroyRecursive(this->root);
}


// **Methods**

/**
 * Method: destroyRecursive(Node* root)
 * ------------------------
 * Helper method for Destructor to destroy a binary search tree and release the memory occupied
 * by all of its nodes
 *
 * @param word: word to be inserted in the Binary Search Tree
 *
 * @type: void
*/
void destroyRecursive(Node* root)
{
	if (root)
	{
		destroyRecursive(root->left);
		destroyRecursive(root->right);
		delete root;
	}
}
/**
 * Method: insertInTree(Node **root, string value)
 * ------------------------
 * Helper method for 'insert(std::string word)' which adds a word to the binary search tree
 *
 * @param **root double pointer to the root Node
 * @param value value to be inserted in the tree
 *
 * @type: void
*/
void insertInTree(Node **root, string value)
{
	// Check if root is a null pointer
	if (!((*root) == nullptr))
	{
		// Compare strings and recursively insert value into the tree  
		if (value < (*root)->word)
		{
			insertInTree(&(*root)->left, value);
		}
		else if (value > (*root)->word)
		{
			insertInTree(&(*root)->right, value);
		}
		else
		{
			return;
		}
	}
	// If root is nullptr then there is no node, insert
	else
	{
		(*root) = new Node;
		(*root)->word = value;
		(*root)->left = nullptr;
		(*root)->right = nullptr;
	}
}
/**
 * Method: insert(std::string word)
 * ------------------------
 * Method which adds a word to the binary search tree. If the word already exists in the tree then nothing happens.
 *
 * @param word: word to be inserted in the Binary Search Tree
 *
 * @type: void
*/
void BinarySearchTree::insert(std::string word)
{
	// Calling helper function to insert word in the tree	
	insertInTree(&root, word);
}
/**
 * Method: uniqueHelper(Node **root, string value)
 * ------------------------
 * Helper method for 'void readFile(std::string fileName)' which inserts only unique
 * string values into the tree. If exists it increments the occurency number of the Node
 *
 * @param **root double pointer to the root Node
 * @param value value to be inserted in the tree if it is not already
 *
 * @type: void
*/
void uniqueHelper(Node **root, string value)
{
	// Check if root is null pointer
	if (!((*root) == nullptr))
	{
		// If root equals the word then word already exists
		if (value == (*root)->word)
		{
			// Increment word occurencies number
			(*root)->occurencies++;
		}
		// Else compare root and passed value and go down through the tree
		else if (value < (*root)->word)
		{
			uniqueHelper(&(*root)->left, value);
		}
		else if (value > (*root)->word)
		{
			uniqueHelper(&(*root)->right, value);
		}
	}
	// If root is null pointer then value not exists in tree, insert value
	else
	{
		(*root) = new Node;
		(*root)->word = value;
		(*root)->left = nullptr;
		(*root)->right = nullptr;
	}
}
/**
 * Method: existsRecursive(Node *root, string value)
 * ------------------------
 * Method which is checking if a value in a passed Node  exists in a recursive way
 *
 * @param **root double pointer to the root Node
 * @param value value to be checked if it exists in the Node
 *
 * @type: void
*/
bool existsRecursive(Node *root, string value)
{
	// Check if root is null pointer
	if (root == nullptr)
		return false;
	// Recursively check if value exists within the binary tree
	if (root->word == value)
		return true;
	if (root->word > value)
		return existsRecursive(root->left, value);
	if (root->word < value)
		return existsRecursive(root->right, value);
	else
		return false;
}

/**
 * Method: exists(std::string word) const
 * ------------------------
 * Method which returns true if word is in the tree, false otherwise
 *
 * exists(std::string word) const: word to be checked if the binary search tree contains it
 *
 * @type: bool
*/
bool BinarySearchTree::exists(std::string word) const
{
	// Call helper function
	return existsRecursive(root, word); // change this to implement the method, returning true if word exists
}

/**
 * Method: inorder_recursive(Node *root)
 * ------------------------
 * Helper function for 'BinarySearchTree::inorder() const' it takes a root and adds all
 * all values into the order_sentece variable with a whitespace between them in inorder fashion
 *
 * @param root a reference to a root node
 * @type: void
*/
void inorder_recursive(Node *root)
{
	if (!(root == nullptr))
	{
		inorder_recursive(root->left);
		order_sentence += root->word;
		order_sentence += " ";
		inorder_recursive(root->right);
	}

}
/**
 * Method: exists(std::string word) const
 * ------------------------
 * Method which generates a string containing the words in the tree in alphabetic order
 *
 * @return order_sentence, the inordered sentence
 *
 * @type: string
*/
string BinarySearchTree::inorder() const
{
	// Reset string variable
	order_sentence = "";
	// Call helper function
	inorder_recursive(root);
	// If string is not empty pop back last value which is white space character from helper function
	if (!(order_sentence.empty()))
		order_sentence.pop_back();
	// Return the inordered sentence
	return order_sentence;

}

/**
 * Method: preorder_recursive(Node *root)
 * ------------------------
 * Helper function for 'BinarySearchTree::postorder() const' it takes a root and adds all
 * all values into the order_sentece variable with a whitespace between them in preorder fashion
 *
 * @param root a reference to a root node
 * @type: void
*/
void preorder_recursive(Node *root)
{
	if (!(root == nullptr))
	{
		order_sentence += root->word;
		order_sentence += " ";
		preorder_recursive(root->left);
		preorder_recursive(root->right);

	}

}
/**
 * Method: preorder() const
 * ------------------------
 * Method which generates a string containing the words in the tree in preorder fashion
 *
 * @return order_sentence, the preordered sentence
 *
 * @type: string
*/
std::string BinarySearchTree::preorder() const
{
	// Reset string variable 
	order_sentence = "";
	// Call helper function
	preorder_recursive(root);
	// If string is not empty pop back last value which is white space character from helper function
	if (!(order_sentence.empty()))
		order_sentence.pop_back();
	// Return the preordered sentence
	return order_sentence;

}
/**
 * Method: post_recursive(Node *root)
 * ------------------------
 * Helper function for 'BinarySearchTree::postorder() const' it takes a root and adds all
 * all values into the order_sentece variable with a whitespace between them
 *
 * @type: void
*/
void post_recursive(Node *root)
{
	if (!(root == nullptr))
	{

		post_recursive(root->left);
		post_recursive(root->right);
		order_sentence += root->word;
		order_sentence += " ";
	}

}
/**
 * Method: postorder() const
 * ------------------------
 * Method which generates a string containing the words in the tree in postorder fashion
 *
 * @return order_sentence, the postordered sentence
 *
 * @type: string
*/
std::string BinarySearchTree::postorder() const
{
	// Reset string variable 
	order_sentence = "";
	// Call helper function
	post_recursive(root);
	// If string is not empty pop back last value which is white space character from helper function
	if (!(order_sentence.empty()))
		order_sentence.pop_back();
	// Return the postordered sentence
	return order_sentence;

}
/**
 * Method: printExists(Node *root, string value)
 * ------------------------
 * A helper function for 'orderFile(std::string fileName)' which prints a
 * root value with its occurencies if exists within the root in the model
 * ( root->value << " : " << occurencies number << new line )
 *
 * @param **root double pointer to the root Node
 * @param value to be found within the root and printed with its occurency number
 *
 * @type: void
*/
void printExists(Node *root, string value)
{
	// Check if root is null pointer, then not found, return
	if (root == nullptr)
		return;
	// If root equals value, is found, print to console, return
	if (root->word == value)
	{
		cout << root->word << " : " << root->occurencies << endl;
		return;
	}
	// Else seek recursevely for the value
	if (root->word > value)
		return printExists(root->left, value);
	if (root->word < value)
		return printExists(root->right, value);
	else
		return;
}
/**
 * Method: orderFile(string fileName)
 * ------------------------
 * Method which prints binary tree using the words order the from a file
 *
 * @param fileName name of file to be proceeded
 *
 * @type: void
*/
void BinarySearchTree::orderFile(string fileName)
{
	// Character used for reading the file
	char ch;
	// String variable where temporary words will be stored
	string word = "";
	// Declare input stream
	ifstream in_stream;
	// Try to open file name passed
	in_stream.open(fileName);
	// Check if stream opened successfully
	if (!(in_stream.is_open())) {
		cerr << "ERROR - unable to open file" << endl;
		return;
	}
	while (in_stream.get(ch))
	{
		// Check if it is not a punctuation character 
		if (!(ispunct(ch)))
		{
			// If character is space or new line then it formed a word in word variable
			if (ch == ' ' || ch == '\n')
			{
				// Print word from tree with its occurencies
				printExists(root, word);
				// Reset word variable
				word = "";

			}
			// If not a character or white space, add current character to word
			else
			{
				word += ch;
			}
		}
	}
	// Close stream
	in_stream.close();
	// Print last value in word variable
	printExists(root, word);
}
/**
 * Method: deepCopyTree(const Node *source)
 * ------------------------
 * A helper function for 'BinarySearchTree(const BinarySearchTree &rhs)'
 * which makes a deep copy of an existing Binary Search Tree
 *
 * @param source reference to the tree from which the deep copy will be made
 *
 * @type: Node*
*/
Node* deepCopyTree(const Node *source)
{
	// Check if source is null pointer
	if (source == nullptr)
	{
		return nullptr;
	}
	// Create new node
	Node* newNode = new Node;
	// Copy new node recursevely and return it so it is a deep copy
	newNode->word = source->word;
	newNode->left = deepCopyTree(source->left);
	newNode->right = deepCopyTree(source->right);
	return newNode;
}
/**
 * Method: readFile(std::string fileName)
 * ------------------------
 * Method which reads a file into a Binary Search Tree Object
 *
 * @param fileName name of file to be proceeded
 *
 * @type: void
*/
void BinarySearchTree::readFile(std::string fileName)
{
	// Character used for reading the file
	char ch;
	// String variable where temporary words will be stored
	string word = "";
	// Declare input stream
	ifstream in_stream;
	// Try to open file name passed
	in_stream.open(fileName);
	// Check if stream opened successfully
	if (!(in_stream.is_open())) {
		cerr << "ERROR - unable to open file" << endl;
		return;
	}
	// While end of file get new character
	while (in_stream.get(ch))
	{
		// Check if it is not a punctuation character
		if (!(ispunct(ch)))
		{
			// Check if it is a space, new line and word variable is not empty
			if ((isspace(ch) || ch == '\n') && word != "")
			{
				// Add word in tree if does not exists
				uniqueHelper((&root), word);
				// Reset word variable
				word = "";
			}
			else
			{
				if (ch != '	' && ch != '\n')
					word += ch;
			}
		}
	}
	// If character is not a newline character, insert last value from word in tree
	if (ch != '\n')
		uniqueHelper((&root), word);
	// Close input stream
	in_stream.close();
}
// **Operator overloads**

/**
 * Operator: BinarySearchTree::operator+(std::string word)
 *
 * Overload function: Inserts a new word into the binary tree
 *
*/
BinarySearchTree& BinarySearchTree::operator+(std::string word)
{
	//void insertInTree(Node **root, string value)
	insertInTree(&root, word);
	//return root; // returns a reference to the modified tree
	return *this;
}

/**
 * Operator: BinarySearchTree::operator=(const BinarySearchTree &rhs)
 *
 * Overload function: Copy assignment operator. Deletes the nodes in tree1, freeing memory
 * and then makes deep copies of all of the nodes in tree2
 *
*/
BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree &rhs)

{
	// Check for self assignment
	if (&rhs != this) {
		// Copy using copy constructor
		BinarySearchTree temp(rhs);
		// Swap out membembers 
		swap(temp.root, root);
	}
	// Temp destroyed from destructor here
	return *this;

}
