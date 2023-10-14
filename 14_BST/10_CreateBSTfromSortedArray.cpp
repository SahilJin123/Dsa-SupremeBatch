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

node* InsertIntoBST(node* root,int data)
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

node* BSTusingInorder(int inorder[],int s,int e)
{
    if(s>e)
    return NULL;

    int mid = s+ (e-s)/2;

    node* root = new node(inorder[mid]);

    root->left = BSTusingInorder(inorder,s,mid-1);
    root->right = BSTusingInorder(inorder,mid+1,e);

    return root;
}
int main()
{
    int inorder[] = {1,2,3,4,5,6,7,8};
    int s = 0;
    int e = 7;

    node* root = BSTusingInorder(inorder,s,e);

    cout<<"Printing Level Order Traversal"<<endl;
    levelOrderTraversal(root);

}