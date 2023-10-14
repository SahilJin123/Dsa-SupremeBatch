void Solve(Node *root,vector<int>& ans,int level)
{
    if(root==NULL)
    return;
    
    if(level == ans.size())
    {
        ans.push_back(root->data);
    }
    
    Solve(root->left,ans,level+1);
    
    Solve(root->right,ans,level+1);
    
    
}

void Solve2(Node* root,vector<int>& ans)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    ans.push_back(root->data);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        
        if(temp==NULL)
        {
            if(!q.empty())
            {
                ans.push_back(q.front()->data);
                q.push(NULL);
            }
        
        }else{
            if(temp->left)
            q.push(temp->left);
            
            if(temp->right)
            q.push(temp->right);
        }
    }
}
vector<int> leftView(Node *root)
{
   // Your code here
//   vector<int>ans;
//   Solve(root,ans,0);
//   return ans;

   vector<int>ans;
   Solve2(root,ans);
   return ans;
}
