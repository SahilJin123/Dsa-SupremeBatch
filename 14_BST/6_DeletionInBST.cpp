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
        this->right=NULL;
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

    while (data!=-1)
    {
        root = InsertIntoBST(root,data);
        cout<<"Enter the Data"<<endl;
        cin>>data;
    }
}

node* FindInBST(node* root,int target)
{
    if(root==NULL)
    return NULL;

    if(root->data == target)
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

// node* deleteNodeInBST(node* root,int target)
// {
//     // Base case
//     if(root==NULL)
//     {
//         return root;
//     }

//     // Step 1 FInd the target Node

//     node* temp = FindInBST(root,target);

//     // Delete the temp 
//     // 4 cases bante hai 
//     // case 1 : temp humara leaf node hai
//     if(root->left==NULL && root->right==NULL)
//     {
//         delete root;
//         return NULL;
//     } else if(root->left != NULL && root->right == NULL){
//         // Case 2 : left not Null hai right bull hai 
//         node* leftChild = root->left;
//         delete root;
//         return leftChild;
//     }else if(root->left==NULL && root->right!=NULL){
//         // Case 3 : left Null hai right not null hai 
//         node* rightChild = root->right;
//         delete root;
//         return rightChild;
//     } else{
//         //case 4  dono left and right not null hai
//         // inorder predecessor of left subtree -> left subtree me max value
//         int rootans = maxValIterative(root->left);
//         root->data = rootans;
//         root->left = deleteNodeInBST(root->left,rootans);  
//         return root;
//     }
// }


node* deletefromBST(node* root,int target)
{
    if(root==NULL)
    {
        return NULL;
    }

    if(root->data == target)
    {
        // isiko delete karna h
        // 4 cases
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        } else if(root->left!=NULL && root->right==NULL){
            // Case 2 : left not Null hai right bull hai 
            node* leftChild = root->left;
            delete root;
            return leftChild;
        }else if(root->left==NULL && root->right!=NULL){
            // Case 3 : left Null hai right not null hai 
            node* rightChild = root->right;
            delete root;
            return rightChild;
        } else{
            //case 4  dono left and right not null hai
            // inorder predecessor of left subtree -> left subtree me max value
            int rootans = maxValIterative(root->left);
            root->data = rootans;
            root->left =  deletefromBST(root->left,rootans);  
            return root;
        }

    }
    else if(root->data > target){

        root->left =  deletefromBST(root->left,target);

    }
    else if(target>root->data)
    {
        root->right = deletefromBST(root->right,target);
    }
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
    node* root = NULL;
    cout<<"Enter the Data"<<endl;
    takeInput(root);
    levelOrderTraversal(root);
    cout<<"After the Deletion : "<<endl;
    int target = 100;
    deletefromBST(root,target);
    levelOrderTraversal(root);
}


