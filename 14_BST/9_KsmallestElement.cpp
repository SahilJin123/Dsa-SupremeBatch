// void Inorder(TreeNode* root,vector<int> &v)
// {
//     if(root==NULL)
//     return;

//     Inorder(root->left,v);
//     v.push_back(root->val);
//     Inorder(root->right,v);
// }
// int kthSmallest(TreeNode* root, int k) {
//     vector<int> v;
//     Inorder(root,v);

//     return v[k-1];
// }

void Inorder(TreeNode* root,int &k,int& ans)
{
    if(root==NULL)
    return;

    Inorder(root->left,k,ans);
    k--;
    if(k==0)
    {
        ans = root->val;
        return;
    }
    Inorder(root->right,k,ans);
}
int kthSmallest(TreeNode* root, int k) {
    int ans = INT_MIN;
    Inorder(root,k,ans);

    return ans;
}