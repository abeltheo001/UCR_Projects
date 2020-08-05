#include <iostream>
#include <fstream>
#include <stack>
#include <sstream>
#include "arithmeticExpression.h"

arithmeticExpression::arithmeticExpression(const string & userString) 
{
    root = 0;
    infixExpression = userString;
}

void arithmeticExpression::infix(TreeNode* input)
{
    if (input == 0)
    {
        return;
    }
    else
    {
        if (priority (input -> data))
        {
            cout << "(";
            infix(input->left);
            cout << input -> data;
            infix(input->right);
            cout << ")" << endl;

        }
    }

}

void arithmeticExpression::prefix(TreeNode* input)
{
    if (input == 0)
    {
        return;
    }
    else
    {
        cout << input -> data << " ";
        prefix(input -> left);
        prefix(input -> right);
    }

}

void arithmeticExpression::postfix(TreeNode* input)
{
    if (input == 0)
    {
        return;
    }
    else
    {
        postfix(input -> left);
        postfix (input -> right);
        cout << input -> data << " ";
    }

}


void arithmeticExpression::buildTree()
{


}

int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ 
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}


void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());

    if(!outFS.is_open())
    {
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS << "digraph G {" << endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

void arithmeticExpression::visualizeTree(ofstream& outFS, TreeNode* temp)
{
 

}


