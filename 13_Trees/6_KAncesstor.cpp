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
    cout<<"Enter the data : "<<endl;
    cin>>data;
    
    if(data==-1)
    return NULL;
    node* root = new node(data);

    
     cout<<"Enter data for left Part of "<<data<<" node "<<endl;
     root->left = buildTree();
     cout<<"Enter data for right Part of "<<data<<" node "<<endl;
     root->right = buildTree(); 

    return root;
}

bool KthAncestor(node* root,node* p,int &k)
{
    if(root==NULL)
    return false;

    if(root->data==p->data)
    {
        // k--;
        return true;
    }

    bool leftans = KthAncestor(root->left,p,k);
    bool rightans = KthAncestor(root->right,p,k);

    if(leftans || rightans)
    {
        k--;
    }
     if(k==0)
    {
        cout<<root->data;
        k=-1;
    }

    return (leftans || rightans);
}
int main()
{
    node * root =NULL;
    root = buildTree();
    int k = 2;

    node* p = new node(4);

    bool ans = KthAncestor(root,p,k);

}