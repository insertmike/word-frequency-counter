test:
	cl /c BinarySearchTree.cpp
	lib /OUT:BST.lib BinarySearchTree.obj
	cl /c test.cpp
	link test.obj BST.lib
	test

counter:
	cl /c BinarySearchTree.cpp
	lib /OUT:BST.lib BinarySearchTree.obj
	cl /c counter.cpp
	link counter.obj BST.lib
	counter 
	
clean:
	del *.obj
	del *.exe
	del *.asm
	del *.lib
	del *.o 