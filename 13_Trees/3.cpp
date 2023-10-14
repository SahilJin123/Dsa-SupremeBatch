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
   node* root =NULL;
   root = buildTree();
   levelOrderTraversal(root);
}