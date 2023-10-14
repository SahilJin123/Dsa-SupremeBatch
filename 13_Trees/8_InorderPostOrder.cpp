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


node* buildTreeInorderPostorder(int inorder[],int Postorder[],int size,int &PostOrderIndex,int InorderStart,int InorderEnd)
{
    // BC
    if(PostOrderIndex < 0 || (InorderStart> InorderEnd))
    {
        return NULL;
    }

    int element = Postorder[PostOrderIndex--];
    node* root = new node(element);
    int i=0;
    for(;i<size;i++)
    {
        if(inorder[i]==element)
        {
            break;
        }
    }
    
    root->right = buildTreeInorderPostorder(inorder,Postorder,size,PostOrderIndex,i+1,InorderEnd);
    root->left = buildTreeInorderPostorder(inorder,Postorder,size,PostOrderIndex,InorderStart,i-1);
    return root;
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
    int inorder[]={40,20,10,50,30,60};
    int postorder[]={40,20,50,60,30,10};
    int size = 6;
    int PostIndex = size-1;
    int InorderStart =0;
    int InorderEnd = size-1;

    node* root=buildTreeInorderPostorder(inorder,postorder,size,PostIndex,InorderStart,InorderEnd);

    levelOrderTraversal(root);
}