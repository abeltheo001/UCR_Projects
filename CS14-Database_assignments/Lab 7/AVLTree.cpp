#include <cstdlib>
#include <iostream>
#include <fstream>
#include "AVLTree.h"

using namespace std;

void AVLTree::insert(const string &x)
{
    //Create a node to be inserted and a temp to locate the root  
    Node* newNode = new Node(x);
    //int heightTracker;

    //if the tree is empty, assign the node to the root
    if (root == NULL)
    {
        root = newNode;
        root -> parent = NULL;
        return;
    }
    
    Node* temp = root; 

    //if not...
    while (temp!= NULL) 
    {
        
        //is the temp's left <= the new node's?
        if (newNode -> data < temp -> data)
        {
            if (newNode -> data == temp -> data)
            {
                return;
            }

             //if so, is the temp's left empty?
            if (temp -> left == NULL)
            {
                //if so, assign the the node to the temp's left and exit.  
                temp -> left = newNode;
                newNode -> parent = temp;
                temp = NULL;
            }
            else //if not, move temp to its left and loop again. 
            {
                temp = temp -> left;
            }
            
            
        }
        else if (newNode -> data == temp -> data)
        {
            return;
        }
        // 
        else 
        {
            if (newNode -> data == temp -> data)
            {
                return;
            }
            
            //is the temp's right greater than the new node's? 
                //if so, is the temp's right empty? 
                if (temp -> right == NULL)
                {
                    //if so, assign the node to the temp's right and exit. 
                    temp -> right = newNode;
                    newNode -> parent = temp;
                    temp = NULL;
                }
                else //if not, move temp to its right and loop again. 
                {
                    temp = temp -> right;
                }
            
                
        }    
    }
    //Node is inserted in its proper location. 

newNode = newNode -> parent;
while (newNode != NULL)
{
    Rebalance(newNode);
    newNode = newNode -> parent;
}
    return;

}

Node* AVLTree::Rebalance(Node *newNode)
{
    determineHeight(newNode);
    if (balanceFactor(newNode) == -2)
    {
        if(balanceFactor(newNode->right) ==1)
        {
            rotateRight(newNode->right);
        }
        rotateLeft(newNode);

    }
    else if (balanceFactor(newNode) == 2)
    {
        if(balanceFactor(newNode->left) == -1)
        {
            rotateLeft(newNode->left);
        }
        rotateRight(newNode);

    }
    return newNode;

}
void AVLTree::rotateRight(Node* currNode)
{
    Node* leftRightChild = currNode -> left -> right;
    if (currNode->parent != NULL)
    {
        replaceChild(currNode -> parent, currNode, currNode->left);
    }
    else
    {
        root = currNode -> left;
        root -> parent = NULL;
    }
    setChild(currNode->left,"right",currNode);
    setChild(currNode,"left",leftRightChild);
    
}

void AVLTree::rotateLeft(Node* currNode)
{
    Node* rightLeftChild = currNode -> right -> left;
    if (currNode->parent != NULL)
    {
        replaceChild(currNode -> parent, currNode, currNode->right);
    }
    else
    {
        root = currNode -> right;
        root -> parent = NULL;
    }
    setChild(currNode->right,"left",currNode);
    setChild(currNode,"right",rightLeftChild);



}

bool AVLTree::replaceChild(Node* parent, Node* currentChild, Node* newChild) 
{
   if (parent->left == currentChild)
      return setChild(parent, "left", newChild);
   else if (parent->right == currentChild)
      return setChild(parent, "right", newChild);
   return false;
}

bool AVLTree::setChild(Node* parent, string whichChild, Node* child) 
{
   if (whichChild != "left" && whichChild != "right")
      return false;

   if (whichChild == "left")
      parent->left = child;
   else
      parent->right = child;
   if (child != NULL)
      child->parent = parent;

   determineHeight(parent);
   return true;
}


int AVLTree::determineHeight(Node* newNode)
{
    int leftHeight = -1;
    if (newNode->left != NULL)
    {
        leftHeight = newNode->left->height;
    }
      
   int rightHeight = -1;
   if (newNode->right != NULL)
   {
       rightHeight = newNode->right->height;
   }

   return newNode -> height = max(leftHeight, rightHeight) + 1;
}


int AVLTree::balanceFactor(Node* x)
{
    int leftHeight = -1;
    if (x->left != NULL )
    {
        leftHeight = x->left->height;
    }
      
   int rightHeight = -1;
   if (x->right != NULL)
   {
       rightHeight = x->right->height;
   }
   return leftHeight - rightHeight;

}

void AVLTree::printBalanceFactors()
{
    printBalanceFactors(root);
    cout << endl;
}

void AVLTree::printBalanceFactors(Node* temp)
{
    if (temp == NULL)
    {
        return;
    }
    else
    {
        printBalanceFactors(temp -> left);
        cout << temp -> data << "(" << balanceFactor(temp) << "), ";
        printBalanceFactors(temp -> right);
    }

}

void AVLTree::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

void AVLTree::visualizeTree(ofstream & outFS, Node *n){
    if(n){
        if(n->left){
            visualizeTree(outFS,n->left);
            outFS<<n->data <<" -> " <<n->left->data<<";"<<endl;    
        }

        if(n->right){
            visualizeTree(outFS,n->right);
            outFS<<n->data <<" -> " <<n->right->data<<";"<<endl;    
        }
    }
}