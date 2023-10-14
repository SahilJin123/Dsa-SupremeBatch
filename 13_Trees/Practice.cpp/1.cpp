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

void LevelOrderTraversal(node* temp)
{
    node* root = temp;
    if(root==NULL)
    {
        return;
    }

    queue<node*> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node* temp = q.front();
        if(temp==NULL && q.size()!=1)
        {
            cout<<endl;
            q.push(NULL);
        }else
        {
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
        }
        q.pop();
    }
}


void InorderTraversal(node* head)
{
    node* root = head;

    if(root==NULL)
    return;

    InorderTraversal(root->left);

    cout<<root->data<<" ";

    InorderTraversal(root->right);

}

void PreorderTraversal(node* head)
{
    node* root = head;

    if(root==NULL)
    return;

    cout<<root->data<<" ";

    PreorderTraversal(root->left);
    PreorderTraversal(root->right);

}

void PostorderTraversal(node* head)
{
    node* root = head;

    if(root==NULL)
    return;

    
    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    cout<<root->data<<" ";

}
node* buildTree()
{
    int data;
    cout<<"Enter the data for the Node"<<endl;
    cin>>data;

    if(data==-1)
    return NULL;
    node* root = new node(data);
    cout<<"Enter the data for the left node of "<<root->data<<endl;
    root->left = buildTree();

    cout<<"Enter the data for the right node of "<<root->data<<endl;
    root->right = buildTree();

    return root;
    
}

int main()
{
    node* root = NULL;
    root = buildTree();
    // cout<<"Level Order Traversal :"<<endl;
    // LevelOrderTraversal(root);
    // cout<<"In Order Traversal :"<<endl;
    // InorderTraversal(root);
    cout<<"Pre Order Traversal :"<<endl;
    PreorderTraversal(root);
    cout<<endl;
    cout<<"Post Order Traversal :"<<endl;
    PostorderTraversal(root);
}