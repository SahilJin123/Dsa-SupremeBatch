#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<list>

using namespace std ;

bool static comp(pair<int,int>& a,pair<int,int>& b)
{
    return a.second<b.second;
}
int solve(int arrival[],int dept[],int& n)
{
    vector<pair<int,int>> data;
    for (int i = 0; i < n; i++)
    {
        data.push_back(make_pair(arrival[i],dept[i]));

        sort(data.begin(),data.end(),comp);
    }

    int cnt = 1;
    int lastdept = data[0].second;
    cout<<"{"<<data[0].first<<" ," <<data[0].second<<"} ,";
    for (int i = 1; i < n; i++)
    {
        if(lastdept<=data[i].first)
        {
            cnt++;
            lastdept = data[i].second;
            cout<<"{"<<data[i].first<<" ," <<data[i].second<<"} ,";
        }
    }
    
    return cnt;
    
}
int main()
{
    int n = 4;
    int arrival[] = {5,8,2,4};
    int dept[] = {7,11,6,5};

    int ans = solve(arrival,dept,n);

    cout<<ans;

}