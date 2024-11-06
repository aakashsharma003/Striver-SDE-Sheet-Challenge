class Solution {
public:
     bool canSortArray(vector<int>& nums) {
       vector<vector<int>>grp;
       for(int i = 0;i < nums.size(); ){
           grp.push_back({});
           int setbits = __builtin_popcount(nums[i]);
           while(i < nums.size() && setbits == __builtin_popcount(nums[i])){
               grp.back().push_back(nums[i]);
               i++;
           }
       }
       int prev_max = -1e9;
       for(auto it: grp){
           int cur_min = 1e9, cur_max = -1e9;
           for(auto val: it){
               cur_min = min(cur_min, val);
               cur_max = max(cur_max, val);
           }
           if(prev_max <= cur_min){
               prev_max = cur_max;
           }
           else
            return false;
       }
       return true;
    }
};