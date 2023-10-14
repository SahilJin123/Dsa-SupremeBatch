#include<iostream>
#include<bits/stdc++.h>
#include<queue>
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
     cout<<"Enter the data: "<<endl;
     cin>>data;

     if(data == -1)
     {
        return NULL;
     }

//   Step A,B and C
     node* root = new node(data);

     cout<<"Enter data for left Part of "<<data<<" node "<<endl;
     root->left = buildTree();
     cout<<"Enter data for right Part of "<<data<<" node "<<endl;
     root->right = buildTree();

    return root;
}
int main()
{
   node* root =NULL;
   root = buildTree();
//    levelOrderTraversal(root);
}