class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0, i = 0;
        for(int i = 0;i < nums.size(); ){
            int j = i, cnt = 0;
            if(nums[i] == 1){
            while(j < nums.size() && nums[i] == nums[j]){
                cnt++;
                j++;
            }
            i = j;
            }
            else{ 
               while(i < nums.size() && nums[i] == 0) 
                i++;
            }
            maxi = max(cnt, maxi);
        }
        return maxi;
    }
};