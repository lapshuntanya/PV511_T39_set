#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T info;
    Node* left;
    Node* right;

    Node(T value) { info = value; left = right = nullptr; }
    void showNode() {
        cout << "INFO: " << info << endl;
        cout << "\t Left: " << left << " Right: " << right << endl;
    }
};