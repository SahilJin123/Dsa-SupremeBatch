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

void maxVal(node* root,int &Maximum)
{
    if(root==NULL)
    return;

    Maximum = root->data;
    maxVal(root->right,Maximum);
}

int maxValIterative(node* root)
{   
    node* temp = root;
    if(root==NULL)
    return -1;

    while (temp->right!=NULL)
    {
        temp = temp->right;
    }

    return temp->data;
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


int main()
{
    node* root = NULL;
    cout<<"Enter the Data"<<endl;
    takeInput(root);
    cout<<"Printing the tree"<<endl;
    levelOrderTraversal(root);
    cout<<endl;

    // int Maximum = 0;
    // maxVal(root,Maximum);

    int Maximum = maxValIterative(root);

    cout<<"Maximum Value is : "<<Maximum;
    
}


// 10 20 5 11 17 2 4 8 6 25 15 -1