#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class TrieNode
{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        
        this->isTerminal = false;
    }
};

void insertWord(TrieNode* root,string word)
{
    // Base Case
    // cout<<"Inserting "<<word<<endl; 
    if(word.length()==0)
    {
        root->isTerminal = true;
        return;
    }

 
    char ch = word[0];
    int index = ch - 'A';

    TrieNode* child;  

    if(root->children[index] !=NULL)  
    {
        child = root->children[index];
    }else{
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // recursion sambhal lega

    insertWord(child,word.substr(1));

}

bool SearchWord(TrieNode* root,string word)
{

    // Base case
    if(word.length()==0)
    {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch-'A';
    TrieNode* child;
    if(root->children[index]!=NULL)
    {
        child = root->children[index];
        return SearchWord(child,word.substr(1));
    }else{
        return false;
    }

    //    SearchWord(child,word.substr(1));

}

void deleteWord(TrieNode* root,string word)
{
    if(word.length()==0)
    {
        root->isTerminal = false;
        cout<<"Word is Deleted"<<endl;
        return;
    }
     
    char ch = word[0];
    int index = ch - 'A'; 
    TrieNode* child;

    if(root->children[index] !=NULL)
    {
        child = root->children[index];
        deleteWord(child,word.substr(1));
    }else{
        cout<<"Word is Not Present"<<endl;
        return;
    }
}
int main()
{
    TrieNode* root = new TrieNode('-');

    string str = "CODING";
    insertWord(root,str);
    insertWord(root,"CODE");
    insertWord(root,"CODER");
    insertWord(root,"BABY");
    insertWord(root,"SHONA");
    insertWord(root,"MONA"); 


    // if(SearchWord(root,"CODING"))
    // {
    //     cout<<"Found"<<endl;
    // }else{
    //     cout<<"Not Found"<<endl;
    // }
    deleteWord(root,str);

    if(SearchWord(root,"CODING"))
    {
        cout<<"Found"<<endl;
    }else{
        cout<<"Not Found"<<endl;
    }
}