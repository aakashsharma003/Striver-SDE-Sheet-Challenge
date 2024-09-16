class Solution {
public:
   
      int lowerBound(vector<int>& nums,  int target){
      int n = nums.size();
        int low = 0, high = n - 1, mid;
        while(low <= high){
             mid = low + (high - low)/2;
            if(nums[mid] >= target){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }

     int upperBound(vector<int>& nums,  int target){
      int n = nums.size();
        int low = 0, high = n - 1, mid;
        while(low <= high){
             mid = low + (high - low)/2;
            if(nums[mid] > target){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low - 1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!nums.size()) return {-1, -1};
         vector<int>ans;
         int lb = lowerBound(nums, target);
         int ub = upperBound(nums, target);
         cout<<lb<<" "<<ub<<endl;
         if(lb >= 0 && lb < nums.size() && nums[lb] == target)
         ans.push_back(lb);
         else
           ans.push_back(-1);
         if(ub < nums.size() && ub >= 0 && nums[ub] == target)
         ans.push_back(ub);
         else
           ans.push_back(-1);
        return ans;
    }
};