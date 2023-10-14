bool solve(TreeNode* root,long long int lowerBound,long long int upperBound)
    {
        if(root==NULL)
        {
            return true;
        }
        
        // Yeh conditon check karega ki jo current root node hai apni range main hai
        bool condition = false;    
        if(root->val > lowerBound && root->val <upperBound)
        {
            condition = true;
        }
        
        // Yeh check karenge ki jo root ke left and 
        // right node hai sabh upar vaali condition ko satisfy kar rahe hai ya nahi
        bool leftans = solve(root->left,lowerBound,root->val);
        bool rightans = solve(root->right,root->val,upperBound);
        
        // Agar tino conditon true honge tabhi ans true ayega tabhi voh valid banega nahi to voh false hoga
        return condition && leftans && rightans;
    }
    bool isValidBST(TreeNode* root) {
     long long  lowerBound = INT64_MIN ;
     long long  upperBound = INT64_MAX ;
     
     bool ans = solve(root,lowerBound,upperBound);

     return ans;

    }