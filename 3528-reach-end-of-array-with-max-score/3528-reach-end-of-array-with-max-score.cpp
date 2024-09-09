class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long n = nums.size();
        pair<long long int, long long int> p = {nums[0], 0};
        long long score = 0;
        long long maxi = (long long)(nums[0]*(n - 1));
        for(int i = 1;i < n - 1;i++){
           if(p.first < nums[i]){
            score +=  (long long)(p.first * (i - p.second));
            p = {nums[i], i};
           }
        }
        score +=  (long long)(p.first*(n - 1 - p.second));
        return maxi = max(maxi, score);
    }
};