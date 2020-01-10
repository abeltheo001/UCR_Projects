#ifndef ARITHMETICEXPRESSION_H
#define ARITHMETICEXPRESSION_H
#include <iostream>
#include <cstdlib>

using namespace std;

struct TreeNode
{
    char data;
    char key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char data, char key):data(data),key(key),left(0),right(0){}
};

class arithmeticExpression
{
    
  private:
    string infixExpression;
    TreeNode* root;

  public:
    /* Initializes an empty tree and sets the infixExpression
    to the value of parameter passed in. */
    arithmeticExpression(const string& infixE);

    /* Converts the infixExpression to its equivalent postfix string
       and then generates the tree and assigns the root node to the 
       root data field. The key for the first node is 'a', 'b' for the second node and so on. */
    void buildTree();

    void infix()
    {
       infix(root);
    }

    void prefix()
    {
       prefix(root);
    }

    void postfix()
    {
       postfix(root);
    }

    /* Calls the recursive visualizeTree function and generates the .png file using system call. */
    void visualizeTree(const string &);

 private:
    int priority(char);

    string infix_to_postfix();

    void infix(TreeNode *);

    void prefix(TreeNode *);

    void postfix(TreeNode *);

    /* Helper function for generating the dotty file. This is a recursive function. */
    void visualizeTree(ofstream &, TreeNode*);
};
#endif
