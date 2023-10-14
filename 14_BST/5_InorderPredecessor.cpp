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
        root = new node(data);
        return root;
    }

    if(root->data > data)
    {
        // left tree
        root->left = InsertIntoBST(root->left,data);
    }else
    {
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

node* FindInBST(node* root,int target)
{
    if(root==NULL)
    {
        return NULL;
    }

    if(root->data==target)
    {
        return root;
    }

    if(root->data > target)
    {
        return FindInBST(root->left,target);
    }else{
        return FindInBST(root->right,target);
    }
}

int maxVal(node* root)
{
    node* temp = root;
    if(root==NULL)
    {
        return -1;
    }

    while (temp->right!=NULL)
    {
        temp = temp->right;
    }

    return temp->data;
    
}
int FindInorderPredecessor(node* root,int target)
{
    node* temp = FindInBST(root,target);

    int ans = maxVal(temp->left);

    return ans;

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
    // root = InsertIntoBST(root,10);
    int target = 20;
    cout<<"Inorder Predecessor : "<<FindInorderPredecessor(root,target);
    
}