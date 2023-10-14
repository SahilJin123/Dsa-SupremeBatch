// #include<iostream>
// #include<bits/stdc++.h>
// #include<queue>
// using namespace std ;
// int main()
// {
//    int val[] = {60,100,120};
//    int wt[] = {10,20,30};
//     int n = 3;
//    int capacity;
//    cin>>capacity;

//     priority_queue<pair<int,int>> pq;
//     for (int i = 0; i < n; i++)
//     {
//         int fraction = val[i]/wt[i];
//         pq.push({fraction,i});
//     }
    
//     int total_value = 0;
//     while (capacity>0)
//     {
//         int top = pq.top().first;
//         int index = pq.top().second;

//         pq.pop();

//         if(capacity>=wt[index])
//         {
//             total_value += top*wt[index];
//             capacity = capacity - wt[index];
//         }else{
//             total_value += top*capacity;
//             capacity = capacity - capacity;
//         }
//     }

//     cout<< total_value;
    
    
// }


#include <iostream>
#include <queue>
using namespace std;

struct Item {
    int value;
    int weight;
};

class Solution {
public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n) {
        int capacity = W;
        priority_queue<pair<double, int>> pq;
        for (int i = 0; i < n; i++) {
            double fraction = static_cast<double>(arr[i].value) / arr[i].weight;
            pq.push({fraction, i});
        }

        double total_value = 0;
        while (!pq.empty() && capacity > 0) {
            double top = pq.top().first;
            int index = pq.top().second;

            pq.pop();

            if (capacity >= arr[index].weight) {
                total_value += top * arr[index].weight;
                capacity = capacity - arr[index].weight;
            } else {
                total_value += top * capacity;
                capacity = capacity - capacity;
            }
        }

        return total_value;
    }
};

int main() {
    int W = 87;
    Item arr[] = {
        {78, 16}, {94, 36}, {87, 43}, {50, 22}, {63, 28}, {91, 10}, {64, 27}, {41, 27}, {73, 37}, {12, 19},
        {68, 30}, {83, 31}, {63, 24}, {68, 36}, {30, 3}, {23, 9}, {70, 18}, {94, 7}, {12, 43}, {30, 24},
        {22, 22}, {20, 85}, {38, 99}, {25, 16}, {21, 14}, {27, 92}, {31, 57}, {24, 63}, {21, 97}, {32, 6},
        {26, 85}, {28, 37}, {6, 47}, {30, 14}, {8, 25}, {46, 83}, {46, 15}, {18, 35}, {15, 44}, {1, 88},
        {9, 77}, {29, 89}, {35, 4}, {2, 55}, {50, 33}, {11, 77}, {19, 40}, {13, 27}, {37, 95}, {40, 96},
        {21, 35}, {29, 68}, {2, 98}, {3, 18}, {43, 53}, {7, 2}, {31, 87}, {42, 66}, {40, 45}, {20, 41},
        {30, 32}, {18, 98}, {22, 82}, {26, 10}, {28, 68}, {7, 98}, {4, 87}, {16, 7}, {34, 20}, {20, 25},
        {29, 22}, {33, 30}, {4, 20}, {71, 19}, {9, 16}, {16, 41}, {50, 97}, {24, 19}, {46, 47}, {2, 22},
        {6, 80}, {39, 65}, {29, 42}, {1, 94}, {1, 35}, {15, 35}
    };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<n;
    Solution solver;
    double result = solver.fractionalKnapsack(W, arr, n);

    cout << "Maximum total value in the knapsack: " << result << endl;

    return 0;
}
