#include <iostream>
#include <string>
#include "RBTree.cpp"

using namespace std;

int main(){
    char keys[] =   {'c','h','a','x','b','z','e'};
    double vals[] = {4.2,5.5,1.2,3.4,7.7,9.1,-1 };
    RBTree<char, double> A(keys, vals, 7);
    cout << "The original tree" << endl;
    A.inorder();

    RBTree<char, double> B = A;
    RBTree<char, double> C;
    C = A;

    cout << "Made using the copy constructor" << endl;
    B.inorder();
    cout << "Made using the copy assignment operator" << endl;
    C.inorder();
    delete &A;
    delete &B;
    delete &C;

    cout << endl << "Now a special case Jeremy wanted to check" << endl;
    int ekeys[]  = {68 ,29 ,39 ,88 ,20 ,66 ,49 ,38 ,69 ,55 ,33};
    string evals[]={"a","b","c","d","e","f","g","h","i","j","k"};
    RBTree<int, string> E(ekeys, evals, 11);
    E.preorder();
    E.inorder();
    E.postorder();
    cout << "Deleting all but 39" << endl;
    E.remove(69);
    for(int i = 0; i < 11; i++){
        if(ekeys[i] != 39 && ekeys[i] != 69){
            E.remove(ekeys[i]);
        }
    }
    E.preorder();
    E.inorder();
    E.postorder();
    return 0;
}