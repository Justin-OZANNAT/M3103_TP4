
#include <iostream>

#include "binarysearchtree.hpp"
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    BSTree<string> myTree ("bidule");

    myTree.show();

    myTree.add("hjkfhdks");
    myTree.add("a");
    myTree.add("b");
    myTree.add("c");
    myTree.add("d");
    myTree.add("e");
    myTree.show();

    return 0;
}
