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
        this->data=data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree()
{
    int data;
    cout<<"Enter the Data"<<endl;
    cin>>data;

    if(data==-1)
    {
        return NULL;
    }

    node* root = new node(data);

    cout<<"Enter the data in left of "<<root->data<<endl;
    root->left = buildTree();

    cout<<"Enter the data in right of "<<root->data<<endl;
    root->right = buildTree();

    return root;

}


void levelOrderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();


        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            q.push(NULL);
        }
        else{

       cout<<temp->data<<" ";

        if(temp->left)
        {
            q.push(temp->left);
        }

        if(temp->right)
        {
            q.push(temp->right);
        }

        }

    }
    
}


void inorderTraversal(node* root)
{

    if(root==NULL)
    return;

    inorderTraversal(root->left);

    cout<<root->data<<" ";

    inorderTraversal(root->right);
}

void PreorderTraversal(node* root)
{

    if(root==NULL)
    return;

    cout<<root->data<<" ";
    PreorderTraversal(root->left);

    PreorderTraversal(root->right);
}

void PostorderTraversal(node* root)
{

    if(root==NULL)
    return;

    PostorderTraversal(root->left);

    PostorderTraversal(root->right);

    cout<<root->data<<" ";
}

void inorderIterative(node* root)
{
    stack<node*> s;
    s.push(root);


    while (true)
    {
        
        node* temp = s.top();

        if(temp->left)
        {
            s.push(temp->left)
            temp = temp->left;
        }else{
            cout<<temp->data<<" ";
            s.pop();
        }
    }
    
}
int main()
{
    node* root = NULL;
    root = buildTree();
    levelOrderTraversal(root);
    cout<<endl;
    inorderTraversal(root);
    cout<<endl;
    PreorderTraversal(root);
    cout<<endl;
    PostorderTraversal(root);
}