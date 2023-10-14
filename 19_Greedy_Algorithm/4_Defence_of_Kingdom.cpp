#include <iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int main() {
  int testcase;
  cin>>testcase;
  while(testcase--)
  {
        long long int x, y, n;
        cin >> x >> y >> n;
        long long int t = n;
        vector<long long int> rowC;
        vector<long long int> colC;

        rowC.push_back(0);
        colC.push_back(0);

        while(t--) {
            long long int a, b;
            cin >> a >> b;
            rowC.push_back(a);
            colC.push_back(b);
        }

        //size of 2D grid
        rowC.push_back(x+1);
        colC.push_back(y+1);

        sort(rowC.begin(), rowC.end());
        sort(colC.begin(), colC.end());

        long long int maxLen = INT64_MIN;
        for(int i=1; i<rowC.size(); i++) {
            long long int a = rowC[i-1];
            long long int b = rowC[i];

            maxLen = max(maxLen, b-a-1);
        }

        long long maxWidth = INT_MIN;
        for(int i=1; i<colC.size(); i++) {
            long long a = colC[i-1];
            long long b = colC[i];

            maxWidth = max(maxWidth, b-a-1);
        }

        // return maxLen * maxWidth;
        cout<<maxLen*maxWidth << endl;
  }
  return 0;
}

// 1
// 15 8 3
// 3 8
// 11 2
// 8 6