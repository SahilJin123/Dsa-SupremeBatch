// #include<iostream>
// #include<bits/stdc++.h>
// #include<vector>
// #include<stack>
// using namespace std ;

// int PivotInRotated_Sorted(vector<int> arr)
// {
//     int s =0;
//     int e = arr.size()-1;
//     int mid = s+(e-s)/2;

//     while (e>=s)
//     {
//         if(arr[mid]>arr[mid+1])
//         return mid;

//         if(arr[mid]<arr[mid-1])
//         return mid-1;

//         if(arr[s]>arr[mid])
//         {
//             e =mid-1;
//         }else{
//             s = mid+1;
//         }
//         mid = s+(e-s)/2;
//     }

//     return -1;
    
// }

// int binaryserach(vector<int> arr,int s,int e,int target)
// {  
//     int start = s;
//     int end = e;
//     // int mid = (start + end)/2;   //This can cause integer overflow bcz if s = 2^(31) - 1 and e=2^(31)-1 then computation of s+e can couse problem .  
//     int mid = start + (end - start)/2 ;
//     while (start<=end)
//     {
//         int element = arr[mid];
//        if (element == target)
//         {
//             return mid;
//         }
//         else if(element > target)
//         {
//             // Search in left
//             end = mid-1;
//         }
//         else{
//             start = mid + 1;
//         }
        
//         mid = (start + end) / 2;
//     }
//     return -1;
    
// }

// int solve(vector<int>arr,int pivot,int target)
// {   
//     int ans =-1;
//     if(arr[pivot]==target)
//     return pivot;
//     if(target>=arr[0] && arr[pivot]>target)
//     {
//        ans= binaryserach(arr,0,pivot,target);
//     }else{
//        ans= binaryserach(arr,pivot+1,arr.size()-1,target);
//     }

//     return ans;
// }
// int main()
// {
//     vector<int> arr{3,4,5,6,7,1,2};

//     int pivot = PivotInRotated_Sorted(arr);
    
//     int ans = solve(arr,pivot,1);
//     cout<<ans;
//     // cout<<"Pivot Index is: "<<ans<<endl;
//     // cout<<"Pivot Element is: "<<arr[ans];
// }


#include<iostream>
#include<vector>
#include<string>
using namespace std;

string Solve(vector<char>& arr, int prev, int curr, int k) {
    if (curr == arr.size()) {
        return "";
    }

    string include = "";
    if (prev == -1 || abs(arr[curr] - arr[prev]) <= k) {
        include = arr[curr] + Solve(arr, curr, curr + 1, k);
    }

    string exclude = Solve(arr, prev, curr + 1, k);

    // Compare the lengths of include and exclude
    if (include.length() > exclude.length()) {
        return include;
    } else {
        return exclude;
    }
}

int main() {
    vector<char> arr{ 'a', 'f', 'c', 'b', 'e', 'd', 'f' };   //afcbedf
    int prev = -1;
    int curr = 0;
    int k = 2;
    string ans = Solve(arr, prev, curr, k);
    cout << ans << endl;
    return 0;
}
