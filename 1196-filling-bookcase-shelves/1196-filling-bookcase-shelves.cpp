class Solution {
public:
   int dp[1001];
   int solve(int indx,int w, vector<vector<int>>&nums, int width){
     if(indx == nums.size()){ 
        return 0;
     }
     if(dp[indx] != -1) return dp[indx];
     int cur = 0, mini = INT_MAX, maxh = 0;
     for(int i = indx;i < nums.size();i++){
        cur += nums[i][0];
        maxh = max(maxh, nums[i][1]);
        if(cur <= width){
           mini = min(maxh + solve(i + 1, 0, nums, width), mini);
        }
        else{
            break;
        }
     }
     return dp[indx] = mini;
   }
    int minHeightShelves(vector<vector<int>>& books, int sw) {
        memset(dp, -1, sizeof(dp));
       return solve(0, 0, books, sw);

    }
};