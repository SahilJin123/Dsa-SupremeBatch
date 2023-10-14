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


node* buildTreeInorderPreorder(int inorder[],int preorder[],int size,int &preOrderIndex,int InorderStart,int InorderEnd)
{
    // BC
    if(preOrderIndex>=size || (InorderStart> InorderEnd))
    {
        return NULL;
    }

    int element = preorder[preOrderIndex++];
    node* root = new node(element);
    int i=0;
    for(;i<size;i++)
    {
        if(inorder[i]==element)
        {
            break;
        }
    }
    root->left = buildTreeInorderPreorder(inorder,preorder,size,preOrderIndex,InorderStart,i-1);
    root->right = buildTreeInorderPreorder(inorder,preorder,size,preOrderIndex,i+1,InorderEnd);

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
    int inorder[]={40,20,50,10,60,30,70};
    int preorder[]={10,20,40,50,30,60,70};
    int size = 7;
    int preIndex = 0;
    int InorderStart =0;
    int InorderEnd = size-1;

    node* root=buildTreeInorderPreorder(inorder,preorder,size,preIndex,InorderStart,InorderEnd);

    levelOrderTraversal(root);
}