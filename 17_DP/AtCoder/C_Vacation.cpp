// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std ;
// // typedef lon
// int main()
// {
//     long long int n;
//     cin>>n;

//     long long int a[n+1] = {0};
//     long long int b[n+1] = {0};
//     long long int c[n+1] = {0};
//     long long int i = 1;
  
//     while(i<=n)
//     {
//         cin>>a[i];
//         cin>>b[i];
//         cin>>c[i];
//         i++;
//     }
//     long long int dpa[n+1] = {0};
//     long long int dpb[n+1] = {0};
//     long long int dpc[n+1] = {0};

//     dpa[1] = a[1];
//     dpb[1] = b[1];
//     dpc[1] = c[1];

//     i = 2;

//     while (i<=n)
//     {
//         dpa[i] = a[i] + max(dpb[i-1],dpc[i-1]);
//         dpb[i] = b[i] + max(dpa[i-1],dpc[i-1]);
//         dpc[i] = c[i] + max(dpb[i-1],dpa[i-1]);
//         i++;
//     }
    
//     cout<<max(dpa[n],max(dpb[n],dpc[n]));

// }


#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
int main()
{
    vector<vector<int>> 
}