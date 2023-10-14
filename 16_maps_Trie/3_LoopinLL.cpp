#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>
#include<string.h>
using namespace std ;

bool checkCircular(node* head)
{

    unordered_map<node*,bool> vis;

    node* temp = head;
    while(temp!=NULL)
    {  
        if(vis[temp])
        {
            return true;
        }

        vis[temp] = true;
        temp = temp->next;
    }
  
    return false;



    // **************************** or ***************************

    // unordered_map<node*,bool> vis;

    // node* temp = head;

    // while(temp!=NULL)
    // {
    //     if(vis.find(temp)!=vis.end())
    //     {
    //         vis[temp] = true;
    //     }else{
    //         return false;
    //     }
    //     temp = temp->next;
    // }
    // return true;
}
int main()
{

}