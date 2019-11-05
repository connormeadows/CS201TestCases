#include <iostream>
#include <string>
#include "RBTree.cpp"

/*Test cases intended to hit every part of the program. The first half tests
 *the methods with the default constructor while the second checks everything
 *after building a tree from the user-defined constructor. */

/*These cases DO NOT test any of the memory management features, 
 *i.e. the destructor, copy constructor, or copy assignment operator */

int main(){
//The first half for testing the default constructor
    RBTree<int, int> A;
    cout << "Tree A created... size should be 0: " << A.size() << endl;

//Now to populate the tree with 10 simple integer elements whose keys equal their values
    for (int i = 1; i < 11; i++){
        A.insert(i,i);
    }

//Time to print the tree :)
    cout << "Take a look at the traverals of your beautiful tree. Aren't they marvelous?" << endl;
    cout << "The size is " << A.size() << endl;
    cout << "Preorder:  ";
        A.preorder();
    cout << "Inorder:   ";
        A.inorder();
    cout << "Postorder: ";
        A.postorder();
    cout << endl;

//Testing search function for the first element, middle element, and last element
    cout << "Let's test the search method." << endl;
    cout << "The key associated with 1 is " << *(A.search(1)) << endl;
    cout << "The key associated with 5 is " << *(A.search(5)) << endl;
    cout << "The key associated with 10 is " << *(A.search(10)) << endl << endl;

//Testing rank for all of the elements. Draw the tree out to see if these are correct.
    cout << "Testing the rank method for a few of the keys..." << endl;
    cout << "The rank of 1 is " << A.rank(1) << endl;
    cout << "The rank of 2 is " << A.rank(2) << endl;
    cout << "The rank of 4 is " << A.rank(4) << endl;
    cout << "The rank of 5 is " << A.rank(5) << endl;
    cout << "The rank of 10 is " << A.rank(10) << endl << endl;

//Testing the select method.
    cout << "What about your search method? Testing with input as 1, 5, then 10" << endl;
    cout << "The smallest element is " << A.select(1) << ", the middle element is " << A.select(5) << ", and the last element is " << A.select(10) << endl << endl;

//Deletions. 
    cout << "Yikes! Deletions are scary. You've got this, though" << endl;
    cout << "Deleting 1 "; A.remove(1);
    cout << "Deleting 4 "; A.remove(4);
    cout << "Deleting 10 ";A.remove(10); cout << endl << endl;

//Testing for failure when the element to be removed isn't in the tree
    cout << "We actually WANT the program to not work for this value, hopefully this shows a 0: " << A.remove(0) << endl;
    cout << endl;

//Checking back in on the traversals and selects
    cout << "The size is " << A.size() << endl;
    cout << "Preorder:  ";
        A.preorder();
    cout << "Inorder:   ";
        A.inorder();
    cout << "Postorder: ";
        A.postorder();
    cout << endl;
    cout << "The smallest element is " << A.select(1) << ", the middle element is " << A.select(4) << ", and the last element is " << A.select(7) << endl << endl;

//Testing the split function. Comment out lines 73 - 89 if you aren't doing the split bonus function.
    cout << "Make like a banana and SPLIT on node 5" << endl;
    RBTree<int, int>B, C;
    A.split(5,B,C);
    cout << "The inorder traversal of the first half, B, the second half, C, and the original tree, A" << endl;
//Not sure if he wants the original to remain intact, but its tested here anyway
    B.inorder(); C.inorder(); A.inorder();
    cout << "The size of B: " << B.size() << " and C: " << C.size() << endl << endl;
    cout << "For good measure let's go ahead and see if the original remained intact" << endl;
    cout << "The size is " << A.size() << endl;
    cout << "Preorder:  ";
        A.preorder();
    cout << "Inorder:   ";
        A.inorder();
    cout << "Postorder: ";
        A.postorder();
    cout << endl;

//The second half of the test, doing everything over again from the user-defined constructor. 
cout << "###################################################" << endl;
//The twist is that the keys are chars and the vals are doubles, although it really doesn't make a difference
    cout << "Now for the moment we\'ve ALL been waiting for\n...\n...\n...\nThe USER-DEFINED constructor" << endl << endl;
    char keys[] =   {'a', 'b', 'c', 'd',  'e'}; 
    double vals[] = {1.0, 3.4, 2.1, 8.9, 100.11};
    RBTree<char, double> D(keys, vals, 5);
    cout << "The size is " << D.size() << endl;
    cout << "Preorder:  ";
        D.preorder();
    cout << "Inorder:   ";
        D.inorder();
    cout << "Postorder: ";
        D.postorder();
    cout << endl;

    cout << "The key associated with a is " << *(D.search('a')) << endl;
    cout << "The key associated with d is " << *(D.search('d')) << endl;
    cout << "The key associated with e is " << *(D.search('e')) << endl << endl;

    cout << "The rank of a is " << D.rank('a') << endl;
    cout << "The rank of b is " << D.rank('b') << endl;
    cout << "The rank of d is " << D.rank('d') << endl;
    cout << "The rank of e is " << D.rank('e') << endl << endl;

    cout << "The smallest element is " << D.select(1) << ", the middle element is " << D.select(3) << ", and the last element is " << D.select(5) << endl << endl;

    cout << "Deleting a "; D.remove('a');
    cout << "Deleting c "; D.remove('c');
    cout << "Deleting e ";D.remove('e');
    cout << endl << endl;

    cout << "Supposed to be 0: " << D.remove(0) << endl << endl;

    cout << "The size is " << D.size() << endl;
    cout << "Preorder:  ";
        D.preorder();
    cout << "Inorder:   ";
        D.inorder();
    cout << "Postorder: ";
        D.postorder();

    return 0;
}