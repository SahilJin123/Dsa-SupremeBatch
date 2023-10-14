class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    void Solve(Node *root,vector<int>& ans,int level)
    {
        if(root==NULL)
        return;
        
        if(level==ans.size())
        {
            ans.push_back(root->data);
        }
        
        Solve(root->right,ans,level+1);
        Solve(root->left,ans,level+1);
    }
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> ans;
       Solve(root,ans,0);
       return ans;
    }
};