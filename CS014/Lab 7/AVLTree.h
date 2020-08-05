#include <cstdlib>
#include <iostream>
#include <cmath>
#include "Node.h"

using namespace std;

class AVLTree
{
    public: 
        AVLTree()
        {
            root = NULL;
        };
        void insert(const string &);
        int balanceFactor(Node*);
        void printBalanceFactors();
        void visualizeTree(const string &);


    private:
        Node* root;
        void printBalanceFactors(Node *);
        void visualizeTree(ofstream &, Node *);
        int determineHeight(Node*);

        Node* rotate(Node*);
        void rotateLeft(Node*);
        void rotateRight(Node*);
        bool replaceChild(Node*,Node*,Node*);
        Node* Rebalance(Node*);
        bool setChild(Node*, string, Node*);
        
};