class Solution {
public:
    int dp[101][101][(1 << 10) + 1];
    int solve(int indx, vector<pair<int,int>>&arr, int prev, int mask){
        if(indx == arr.size()) return 0;
        if(dp[indx][prev][mask] != -1) return dp[indx][prev][mask];
        int val = arr[indx].first, row = arr[indx].second;
        int x = 0, y = 0;
        if((val > prev || prev == 0) && !(mask & (1 << row))){
           x = val + solve(indx + 1, arr, val, (mask | (1 << row)));
        }
         
         y = solve(indx + 1, arr, prev, mask);

         return dp[indx][prev][mask] = max(x, y);
    }  
    int maxScore(vector<vector<int>>& grid) {
      vector<pair<int,int>>arr;
      for(int i = 0;i < grid.size();i++){
        for(int j = 0;j < grid[0].size();j++)
            arr.push_back({grid[i][j], i});
    }
    sort(arr.begin(), arr.end());
    memset(dp, -1, sizeof(dp));
    return solve(0, arr, 0, 0);
    }
};