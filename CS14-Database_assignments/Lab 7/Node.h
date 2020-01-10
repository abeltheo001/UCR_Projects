#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

class Node
{
    Node(string data):data(data),left(0),right(0),parent(0),height(0){};

    private: 
    string data;
    Node* left;
    Node* right;
    Node* parent;
    int height;
    friend class AVLTree;
};
