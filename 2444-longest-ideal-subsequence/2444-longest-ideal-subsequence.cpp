class Solution {
public:
    int dp[100001][27];
    int solve(int i, string &s, int &k, int prev){
      if(i >= s.size()) return 0;
      if(dp[i][prev + 1] != -1) return dp[i][prev + 1];
      int take = 0;
      if(prev ==  -1 || abs((s[i] - 'a') - prev) <= k)
      take += 1 + solve(i + 1, s, k, s[i] - 'a');
      int nottake = solve(i + 1, s, k, prev);
      return dp[i][prev + 1] = max(take, nottake); 
    }
    int longestIdealString(string s, int k) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, s, k, -1);
    }
};