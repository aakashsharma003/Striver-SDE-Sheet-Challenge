class Solution {
public:
    int dp[1001][1001];
    int solve(int i, int j, vector<int>& arr, vector<int>&pref){
        if(i >= j) return 0; 
        int left = 0, right = 0;

        if(dp[i][j] != -1) return dp[i][j];
        
        left += pref[j] - pref[i] - solve(i + 1, j, arr, pref);
        if(i > 0 && j > 0)
        right = right + pref[j - 1] - pref[i - 1] - solve(i, j - 1, arr, pref);
        else
        right = right + pref[j - 1] - solve(i, j - 1, arr, pref);

        return dp[i][j] = max(left, right); 
    }
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int>pref(n, 0);
        pref[0] = stones[0];
        for(int i = 1;i < n;i++)
        pref[i] = pref[i - 1] + stones[i];

        memset(dp, -1, sizeof(dp)); 
        return solve(0, n - 1, stones, pref);
        // return 0;
    }
};