#include <iostream>

using namespace std;

struct Node {
    Node *lchild;
    Node *rchild;
    int data;
};

Node *RSearchTree(Node *t, int key ) {
    if (t == NULL) 
        return NULL;

    if (t->data == key)
        return t;

    else if (t->data < key) 
        return RSearchTree(t->rchild, key);
    else 
        return RSearchTree(t->lchild, key);
}

Node *ISearchTree(Node *t, int key) {

    while (t != NULL) {
        if (t->data == key)
            return t;
        else if (t->data < key)
            t = t->rchild;
        else 
            t = t->lchild;
    }

    return NULL;
}

void Insert(Node *t, int key) {
    Node *r = NULL;

    while (t != NULL) {
        r = t;

        if (t->data == key) 
            return;
        else if (t->data > key) {
            t = t->lchild;
        }
        else { 
            t = t->rchild;
        }
    }

    Node *temp = new Node {0, 0, key};
    if (r->data > key)
        r->lchild = temp;
    else
        r->rchild = temp;
}