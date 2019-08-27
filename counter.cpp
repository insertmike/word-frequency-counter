/*
 * Author: 40342250
 * Purpose: Coursework Project 2
 * Details: An application which counts the number of occurencies of all words in a text file
 * Language: C++
 * Last modified: 4/1/2019
*/
#include<iostream>
#include "BinarySearchTree.h"
using namespace std;


int main(int argc, char** argv) {
	// Declaring a Binary Search Tree Object
	BinarySearchTree *tree;
	enum Choice
	{
		SENTENCES_TEST = 1,
		SINGLE_WORDS = 2,
		QUIT = 3
	};
	cout << "Hello, this application will help you to count the occurencies of each word in a text file!" << endl;
	int flag = 1;
	while (flag) {
		// Choice to equals exit value to prevent an infinity loop if user enter characters
		int choice = 3;
		// Prompt for choice
		cout << "------------------------------" << endl;
		cout << "Please select a file to read: " << endl;
		cout << "1 - sentences_test.txt , " << endl;
		cout << "2 - single_words_test.txt , " << endl;
		cout << "3 - Exit " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			// Allocating a new Binary Search Tree Object
			tree = new BinarySearchTree();
			// Reading the file into the Binary Tree Object adding unique values only
			tree->readFile("sentences_test.txt");
			// Print binary tree using the words order the from original file
			tree->orderFile("sentences_test.txt");
			// Deleting object
			delete(tree);
			break;
		case 2:
			// Allocating a new Binary Search Tree Object
			tree = new BinarySearchTree();
			// Reading the file into the Binary Tree Object 
			tree->readFile("single_words_test.txt");
			// Print file in its original order
			tree->orderFile("single_words_test.txt");
			// Deleting object
			delete(tree);
			break;
		case 3:
			flag = 0;
			break;
		default:
			cerr << "ERROR - Invalid input" << endl;
			break;
		}
	};
	return 0;
}