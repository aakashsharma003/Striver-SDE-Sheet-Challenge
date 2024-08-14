class Solution {
public:
    int dp[101][101];
    int uniquePaths(int m, int n) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(i == 0 && j == 0) continue;
                int top = 0, left = 0;
                if (i >= 1)
                    top += dp[i - 1][j];
                if (j >= 1)
                    left += dp[i][j - 1];

                dp[i][j] = top + left;
            }
        }

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                cout<<dp[i][j]<<" ";
            }
        }

        return dp[m - 1][n - 1];
    }
};