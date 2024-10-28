class Solution {
public:
    bool isPresent(long long num, vector<int>& nums){
        int low = 0, high = nums.size() - 1; 
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] > num){
                high = mid - 1;
            }
            else if(num == nums[mid]) return true;
            else low = mid + 1;
        }
        return false;
    }
  
    int longestSquareStreak(vector<int>& nums) {
        int ans = -1;
        sort(nums.begin(), nums.end());
        for(int i = 0;i < nums.size();i++){
            int streak = 0;
            long long cur = nums[i];
            while(cur < 100000 && isPresent(cur, nums)){
                streak++;
                cur *= cur;
            }
            // cout<<streak<<" "<<cur<<endl;
            if(streak >= 2)
            ans = max(ans, streak);
        }
        return ans;
    }
};