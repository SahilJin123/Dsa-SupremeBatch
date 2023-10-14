
vector<long long> solve(long long int arr[],long long int n, long long int k ) {
        deque<long long> q;
        //process first window of size k 
        for(long long int i=0; i<k; i++) {
                if(arr[i] < 0) {
                        q.push_back(i);
                }
        }

        
        vector<long long> ans; 
        //remaining window ko process kro
        for(long long int i=k; i<n; i++) {
                //answer dedo purani wondow ka 
                if(q.empty()) {
                        // cout << 0 << " ";
                        ans.push_back(0);
                }
                else {
                        // cout << arr[q.front()] << " ";
                        ans.push_back(arr[q.front()]);
                }

                //out of window elements ko remove krdo
                while((!q.empty()) && (i - q.front() >= k)) {
                        q.pop_front();
                }

                //check current element for insertion 
                if(arr[i] < 0 ) 
                        q.push_back(i);

        }

        //answer print karonfor last window
       if(q.empty()) {
                // cout << 0 << " ";
                ans.push_back(0);
        }
        else {
                // cout << arr[q.front()] << " ";
                ans.push_back(arr[q.front()]);
        }

    return ans;
}