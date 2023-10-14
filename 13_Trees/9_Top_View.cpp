#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std ;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data = data;
        this->left  = NULL;
        this->right = NULL;
    }
};

Node* buildTree()
{
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;

    Node* root = new Node(data);

    if(data== -1)
    {
        return NULL;
    }

    cout<<"Enter the data at the left of node "<<data<<endl;
    root->left = buildTree();
    cout<<"Enter the data at the right of node "<<data<<endl;
    root->right = buildTree();

    return root;
}

void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        /* code */
        Node* temp = q.front();
        q.pop();
        cout<<temp->data;

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

void Inorder(Node* root)
{
    if(root==NULL)
    return;

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void Preorder(Node* root)
{
    if(root==NULL)
    return;

    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right); 
}

void Postorder(Node* root)
{
    if(root==NULL)
    return;
    
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}

void PrintTopView(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    // Create map for TopView
    map<int,int> topNode;

    queue<pair<Node*,int>> q;
    q.push({root,0});

    while (!q.empty())
    {
        Node* temp = q.front().first;
        int hd = q.front().second;
        q.pop();

        if(topNode.find(hd)==topNode.end())
        {
            topNode[hd] = temp->data;
        }

        if(temp->left)
        {
            q.push({temp->left,hd-1});
        }

        if(temp->right)
        {
            q.push({temp->right,hd+1});
        }
    }

    cout<<"Printing the Answer"<<endl;
    for(auto i: topNode)
    {
        cout<<i.first<<" -> "<<i.second<<endl;
    }
    
}

void PrintBottomView(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    // Create map for TopView
    map<int,int> topNode;

    queue<pair<Node*,int>> q;
    q.push({root,0});

    while (!q.empty())
    {
        Node* temp = q.front().first;
        int hd = q.front().second;
        q.pop();

        // if(topNode.find(hd)==topNode.end())
        // {
            topNode[hd] = temp->data;
        // }

        if(temp->left)
        {
            q.push({temp->left,hd-1});
        }

        if(temp->right)
        {
            q.push({temp->right,hd+1});
        }
    }

    cout<<"Printing the Answer"<<endl;
    for(auto i: topNode)
    {
        cout<<i.first<<" -> "<<i.second<<endl;
    }
    
}

int main()
{
    Node* root;
    root = buildTree();
    // PrintTopView(root);
    // PrintBottomView(root);
    vector<int> ans;
    BoundaryTraversal(root,ans);

    for(auto i: ans)
    {
        cout<<i<<" ";
    }
}

// 10 20 30 -1 -1 40 60 -1 -1 -1 80 50 -1 70 -1 -1 90 -1 -1