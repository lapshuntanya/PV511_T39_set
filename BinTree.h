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


template <typename U>
class BinTree {
    Node<U>* root; //Вказівник на перший вузол у дереві

    void showSubTree(Node<U>* p) {
        if (p!=nullptr) {
            showSubTree(p->left);
            cout <<p->info << " ";
            showSubTree(p->right);
        }
    }

    void delNode(Node<U>*p) {
        if (p!= nullptr) {
            delNode(p->left);
            delNode(p->right);
            cout << "DEL: " << p->info << endl;
            delete p;
        }
    }
public:
    BinTree() { root = nullptr; }
    ~BinTree() {
        delNode(root);
        root = nullptr;
    }

    void insert(U value) {
       Node<U>* item = new Node<U>(value);

        if (root == nullptr)
            root = item;
        else {
            //Знаходимо місце для вставки вузла
            Node<U>* p = root;
            Node<U>* prevPlace = root;
            while (p != nullptr) {
               // if (item->info < p->info) p = p->left;
               // else p = p->right;
                prevPlace = p;
                p = (item->info < p->info) ? p->left : p->right;
            }

            //Привʼязуємно новий вузол до дерева
            if (item->info < prevPlace->info)
                prevPlace->left = item;
            else
                prevPlace->right = item;
        }
    }

    Node<U>* search(U value) {
        //Повернути адресу вузла зі значенням value
        //Якщо value немає в дереві, то повернути nullptr
        Node<U>*p = root;
        while (p!=nullptr && p->info != value) {
            p = (value < p->info) ? p->left : p->right;
        }

        return p;
    }

    //Повний обхід дерева
    void showTree() {
        if (root == nullptr)
            cout << "Дерево контейнерів порожнє!" << endl;
        else {
            showSubTree(root);
        }
    }

};