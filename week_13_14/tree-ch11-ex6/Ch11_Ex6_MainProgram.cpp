
//Data
//68 43 10 56 77 82 61 82 33 56 72 66 99 88 12 6 7 21 -999

#include <iostream>
#include "binarySearchTree.h"

using namespace std;

int main()
{
    bSearchTreeType<int>  treeRoot, otherTreeRoot;

    int num;

    cout << "Enter numbers ending with -999" << endl;
    cin >> num;

    while (num != -999)
    {
        treeRoot.insert(num);
        cin >> num;
    }

    cout << endl << "Tree nodes in inorder: ";
    treeRoot.nonRecursiveInTraversal();

    cout << endl << "Tree nodes in preorder: ";
    treeRoot.nonRecursivePreTraversal();

    cout << endl << "Tree nodes in postorder: ";
    treeRoot.nonRecursivePostTraversal();
    cout << endl;

    return 0;
}