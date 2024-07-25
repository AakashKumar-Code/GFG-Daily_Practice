//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        int freq[26]={0};
        
        int cnt=0;
        
        int n=str.length();
        
        for(int i=0; i<n; i++){
            if(str[i]==' ') continue;
            else freq[str[i]-'a']++;
        }
        int totalCnt=0;
        
        for(int i=0; i<26; i++){
            if(freq[i]==0) cnt++;
            else totalCnt+=(freq[i]-1);
        }
        
        if(cnt<=k && cnt<=totalCnt) return 1;
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends