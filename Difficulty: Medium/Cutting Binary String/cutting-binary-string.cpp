class Solution {
  public:
  
    unordered_set<long> selectedSet;
    int maxi;
    int dp[33]; // 🧾 Memoization array (max 32 length)

    int helper(int ind, string s, int n){
        if(ind == n) return 0;
        if(s[ind] == '0') return 32;
        if(dp[ind] != -1) return dp[ind]; // 📌 Already computed

        int ans = 32;
        long curr = 0;

        for(int i = ind; i < n; i++){
            curr = (curr << 1) + (s[i] - '0');
            if(selectedSet.count(curr)){
                ans = min(ans, 1 + helper(i + 1, s, n));
            }
        }

        return dp[ind] = ans;
    }
    
    Solution(){
        maxi = INT_MAX;
        for(long i = 1; i < maxi; i *= 5){
            selectedSet.insert(i);
        }
    }
  
    int cuts(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));  // 🔧 Initialize dp
        int ans = helper(0, s, n);
        if(ans >= 32) return -1;
        return ans;
    }
};