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

node* InsertIntoBST(node* root,int   data)
{
    if(root==NULL)
    {
        // this id the first node we have to create
        root = new node(data);
        return root;
    }

    // not the first node

    if(root->data > data)
    {
        // insert in left
        root->left = InsertIntoBST(root->left,data);
    }else{
          root->right = InsertIntoBST(root->right,data);
    }

    return root;
}

void takeInput(node* &root)
{
    int data;
    cin>>data;

    while(data!=-1)
    {
        root = InsertIntoBST(root,data);
        cout<<"Enter the Data"<<endl;
        cin>>data;
    }
}

bool FindInBST(node* root,int target)
{
    if(root==NULL)
    return false;

    if(root->data==target)
    {
        return true;
    }

    if(root->data > target)
    {
        return FindInBST(root->left,target);
    }else{
        return FindInBST(root->right,target);
    }

}

void minVal(node* root,int &minimum)
{
    if(root==NULL)
    return;

    minimum = root->data;
    minVal(root->left,minimum);
}


void levelOrderTraversal(node* root)
{
    queue<node*> q;
    // Initially Push Root Node
    q.push(root);
    q.push(NULL);
    // Steps A,B and C

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
        q.push(temp->left); 

        if(temp->right)
        {
         q.push(temp->right); 
        }
       }
        
    }
    
}

void PreOrder(node* root)
{
    if(root==NULL)
    return ;

    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(node* root)
{
    if(root==NULL)
    return ;

    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

void PostOrder(node* root)
{
    if(root==NULL)
    return ;

    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    node* root = NULL;
    cout<<"Enter the Data"<<endl;
    takeInput(root);
    cout<<"Printing the tree"<<endl;
    levelOrderTraversal(root);
    cout<<endl;

    bool ans = FindInBST(root,15);
    if(ans)
    cout<<"Target Found";
    else
    cout<<"Target Not Found";
    

}