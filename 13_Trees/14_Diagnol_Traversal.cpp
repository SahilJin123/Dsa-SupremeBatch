map<int,vector<int>> mp;

void Solve(Node *root,int d)
{
    if(root==NULL)
    return;
    
    mp[d].push_back(root->data);
    
    Solve(root->left,d+1);
    
    Solve(root->right,d);
}
vector<int> diagonal(Node *root)
{
  mp.clear();
   vector<int>ans;
   int n = mp.size();
   Solve(root,0);
//   for(auto i : mp )
//   {
//       for(auto j :i.second)
//       {
//           ans.push_back(j);
//         //   cout<<j;
//       }
//   }
    for (auto& entry : mp) {
        ans.insert(ans.end(), entry.second.begin(), entry.second.end());
    }
   return ans;
   
}

void Helper(TreeNode* root,vector<int>& ans)
{
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty())
    {
        TreeNode* temp = q.front();
        q.pop();
        
        while(temp!=NULL)
        {
            ans.push_back(temp->val);
            if(temp->left) 
            q.push(temp->left);
            
            temp = temp->right;
        }
    }
}

vector<int> Solution::solve(TreeNode* A) {
    
    vector<int> ans;
    Helper(A,ans);
    return ans;
}
