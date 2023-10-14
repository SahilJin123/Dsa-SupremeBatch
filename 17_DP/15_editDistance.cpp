class Solution {
public:
    int Solve(string& a, string& b,int i,int j)
    {
        if(i == a.length())
        {
            return b.length() - j;
        }

        if( j == b.length())
        {
            return a.length() - i;
        }

        int ans = INT_MAX;
        if(a[i]==b[j])
        {
            ans = Solve(a,b,i+1,j+1);
        }else{
            int ins = Solve(a,b,i,j+1) + 1;
            int del = Solve(a,b,i+1,j) + 1;
            int repl = Solve(a,b,i+1,j+1) + 1;
            ans = min(ins,min(del,repl));
        }

        return ans;
    }
    int minDistance(string word1, string word2) {

        if(word1.length()==0)
          return word2.length();

        if(word2.length()==0)
           return word1.length();

        int i  = 0;
        int j = 0;
        return Solve(word1,word2,i,j);
    }
};