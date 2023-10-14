TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
    // if(root==NULL)
    // {
    //     return NULL;
    // }
    // if(root->val == p->val)
    // {
    //     return p;
    // }else if(root->val == q->val)
    // {
    //     return q;
    // }

    // if((root->val > p->val && root->val <q->val) || (root->val < p->val && root->val > q->val) )
    // {
    //     return root;
    // }else if(root->val > p->val && root->val > q->val)
    // {
    //     return lowestCommonAncestor(root->left,p,q);
    // }else{
    //     return lowestCommonAncestor(root->right,p,q);
    // }




    // *******************OR*****************************************************

    if(root==NULL)
    {
        return NULL;
    }

        if((root->val > p->val && root->val >q->val))
    {
        return lowestCommonAncestor(root->left,p,q);
    }else if((root->val < p->val && root->val < q->val))
    {
        return lowestCommonAncestor(root->right,p,q);
    }

    return root;

}