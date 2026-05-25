#include "BinTree.h"

int main() {

    BinTree<int> tree;

    tree.insert(8);
    tree.insert(11);
    tree.insert(2);
    tree.insert(0);
    tree.insert(66);
    tree.insert(1);
    tree.insert(7);
    tree.insert(656);
    tree.insert(13);
    tree.insert(57);


    cout << endl;

    Node<int>*p = tree.search(8);
    if (p) p->showNode();
    else cout << "not found!\n";


    p = tree.search(-8);
    if (p) p->showNode();
    else cout << "not found!\n";

    return 0;
}