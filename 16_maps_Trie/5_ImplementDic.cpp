#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std ;

class TrieNode
{
    public:
    char data;
    TrieNode* children[26];
    bool isterminal;

    TrieNode(char data)
    {
        this->data = data;

        for(int i =0;i<26;i++)
        {
            children[i] = NULL;
        }
        this->isterminal = false;
    }
};

void insertWord(TrieNode* root,string word)
{
    if(word.length()==0)
    {
        root->isterminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    if(root->children[index]!=NULL)
    {
        child = root->children[index];
    }else{
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    insertWord(child,word.substr(1));
}

bool SearchWord(TrieNode* root,string word)
{
    if(word.length()==0)
    {
        return root->isterminal;
    }

    char ch = word[0];
    int index = ch -'a';
    TrieNode* child;
    if(root->children[index] !=NULL)
    {
        child = root->children[index];
        return SearchWord(child,word.substr(1));
    }else{
        return false;
    }
}

void deleteWord(TrieNode* root,string word)
{
    if(word.length()==0)
    {
        root->isterminal = false;
        return;
    }

    char ch = word[0];
    int index = ch -'a';
    TrieNode* child;

    if(root->children[index] !=NULL)
    {
        child = root->children[index];
        deleteWord(child,word.substr(1));
    }else{
        return;
    }
}


void storeSuggestions(TrieNode* curr,vector<string>& temp,string &prefix)
{
    if(curr->isterminal)
    {
        temp.push_back(prefix);
    }

    // a to z tak choices dedo
    for(char ch ='a';ch<='z';ch++)
    {
        int index = ch- 'a';

        TrieNode* next = curr->children[index];

        if(next!=NULL)
        {
            prefix.push_back(ch);
            storeSuggestions(next,temp,prefix);
            prefix.pop_back();
        }
    }
}




vector<vector<string> > getSuggestions(TrieNode* root,string input)
{
    TrieNode* prev = root;
    vector<vector<string> > output;
    string prefix  = "";

    for (int i = 0; i <input.length(); i++)
    {
        char lastch = input[i];

        int index = lastch - 'a';

        TrieNode* curr = prev->children[index];

        if(curr == NULL)
        {
            break;
        }else{
            // iske andhar mai saare suggestion store karunga
            vector<string> temp;
            prefix.push_back(lastch);
            storeSuggestions(curr,temp,prefix);
            output.push_back(temp);
            prev = curr;
        }  
    }
    return output; 
}

int main()
{
    vector<string> v;
    v.push_back("love");
    v.push_back("lover");
    v.push_back("loving");
    v.push_back("last");
    v.push_back("lost");
    v.push_back("lane");
    v.push_back("lord");

    string input = "lovi";

    TrieNode* root = new TrieNode('-');
    for(int i =0;i<v.size();i++)
    {
        insertWord(root,v[i]);
    }

    vector<vector<string> > ans = getSuggestions(root,input);

    cout<<"Printing the Answer : "<<endl;

    for(int i=0;i<ans.size();i++) 
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}



