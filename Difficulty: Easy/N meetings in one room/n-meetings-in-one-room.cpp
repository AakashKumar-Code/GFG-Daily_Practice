//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<vector<int>>tmp;
        for(int i=0; i<n; i++){
            tmp.push_back({end[i], start[i]});
        }
        sort(tmp.begin(), tmp.end());
        
        int ans=0;
        int prev_end=-1;
        for(int i=0; i<n; i++){
            int cur_start=tmp[i][1];
            int cur_end=tmp[i][0];
            
            if(cur_start>prev_end){
                ans++;
                prev_end=cur_end;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends