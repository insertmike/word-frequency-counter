# C++ Module Coursework :blue_book:
This file reports details about my C++ Module Coursework for `Edinburgh Napier University`

*Submitted:*  7 April 2019

*Grade:* 100% ( 36/36 )

*Graded on:* 27 April 2019


## General Description
The coursework contains two parts:

  - *Part A:* Implementing a Binary Search Tree data structure storing string data for efficient searching.
  
 - *Part B:* Creating an application, which uses the Binary Search Tree implemented to count the frequencies of each word in a text file.
 
**Overall Approach:** 
The output approach I took is to print the words in their correct order, because it is user-friendly and easier to interact: 
<pre>
 'word' : occurencies  \n,
 'word' : occurencies  \n,
  ...   
</pre>

In terms of programming: 
- Time and Space efficient structures
- Meaningful variable names.
- Correct indentation.
- Suitable comments.

### Application Specification

1. **Part A**
  - The implementation of the BinarySearchTree class provided is correct and it is passing all tests
  from the *test-folder* > *test-tree-functionalities.cpp*

   <img src="https://user-images.githubusercontent.com/45242072/63807227-fdc48b00-c925-11e9-8e8b-e241741b1f41.png" alt="table-1" >
        

   <img src="https://user-images.githubusercontent.com/45242072/63807372-3e240900-c926-11e9-870c-863e6974f5c5.png" alt="table-2" >
   
2. **Part B**
  - There is application that reads in a text file and outputs to the console the number of times each word in that file occurs:
  
  *Example:*:
<pre>
Input file text: “The C programming language is very useful. The C programming language is a low level language”

Output:
The: 2
C: 2
programming: 2
language: 3
is: 2
very: 1
useful: 1
a: 1
low: 1
level: 1

</pre>
  
### How to run locally
**Part A**
1. Extract the *test-tree-functuonalities.cpp* from the *test-application* folder to the root folder.
2. Remove *counter.cpp* file from the root folder.
2. Open the project under your *build-chain* *(e.g Visual Studio)*
3. Run main 

**Part B**
1. Extract the test text files from the *test-application* folder to the root folder.
2. Open the project under your *build chain*
3. Run main

