class Solution {
public:
    void PrintLeftBoundary(Node* root,vector<int>& ans)
{
    if(root==NULL)
    return;

    if(root->left==NULL && root->right==NULL)
    {
        return;
    }

    ans.push_back(root->data);

    if(root->left)
    PrintLeftBoundary(root->left,ans);
    else
    PrintLeftBoundary(root->right,ans);
}

void PrintLeafBoundary(Node* root,vector<int>& ans)
{
     if(root==NULL)
    return;
    
     if(root->left==NULL && root->right==NULL)
    {
        ans.push_back(root->data);
    }

    PrintLeafBoundary(root->left,ans);
    PrintLeafBoundary(root->right,ans);
}


void PrintRightBoundary(Node* root,vector<int>& ans)
{
    if(root==NULL)
    return;

    if(root->left==NULL && root->right==NULL)
    {
        return;
    }
    
    if(root->right)
    PrintRightBoundary(root->right,ans);
    else
    PrintRightBoundary(root->left,ans);


    ans.push_back(root->data);

    
}


void BoundaryTraversal(Node* root,vector<int>& ans)
{
    if(root==NULL)
    return;

    ans.push_back(root->data);
    // A Left View

    PrintLeftBoundary(root->left,ans);

    // B Leaf Boundary
    PrintLeafBoundary(root,ans);

    // C Right Boundary

    PrintRightBoundary(root->right,ans);

}
vector <int> boundary(Node *root)
{
    //Your code here
    if(root->left==NULL && root->right==NULL)
    {
        return {root->data};
    }
    vector<int>ans;
    BoundaryTraversal(root,ans);
    return ans;
}