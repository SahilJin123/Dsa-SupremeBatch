#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree()
{
    int data;
    cout<<"Enter the root data"<<endl;
    cin>>data;

    if(data==-1)
     return NULL;

     node* root = new node(data);

     cout<<"Enter the data in the left Node of "<<data<<endl;
     root->left = buildTree();

     cout<<"Enter the data in the right Node of "<<data<<endl;
     root->right = buildTree();

     return root;
}

void InOrderTraversal(node* root)
{
    node* temp = root;

    if(temp==NULL)
    return;

    // LNR
    // Step 1 : left pe jaana hai
    InOrderTraversal(temp->left);

    // step 2: current node pe jaana hai
    cout<<temp->data;


    // step 3 : right pe jaana hai
      InOrderTraversal(temp->right);

}

void PreOrderTraversal(node* root)
{
    node* temp = root;

    if(temp==NULL)
    return;

    // NLR

    // step 1: current node pe jaana hai
    cout<<temp->data;

    // Step 2 : left pe jaana hai
    PreOrderTraversal(temp->left);

    // step 3 : right pe jaana hai
    PreOrderTraversal(temp->right);

}

void PostOrderTraversal(node* root)
{
    node* temp = root;

    if(temp==NULL)
    return;

    // LRN

    // Step 1 : left pe jaana hai
    PostOrderTraversal(temp->left);

    // step 2 : right pe jaana hai
    PostOrderTraversal(temp->right);  

     // step 3: current node pe jaana hai
    cout<<temp->data;

}

int main()
{
    node* root = NULL; 
    root = buildTree(); 
}