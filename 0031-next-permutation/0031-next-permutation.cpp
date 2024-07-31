class Solution {
public:


    void nextPermutation(vector<int>& nums) {
        int indx = -1, n = nums.size();
        for(int i = n - 1;i >= 1;i--){
            if(nums[i-1] < nums[i]){
                indx = i - 1;
                break;
            }
        }
        if(indx == -1){
             reverse(nums.begin() + 0,nums.end());
             return;
        }
        for(int i = n - 1;i > indx;i--){
            if(nums[i] > nums[indx]){
                // cout<<nums[i]<<" "<<nums[indx]<<endl;
                swap(nums[i], nums[indx]);
                break;
            }
        }
        // cout<<indx<<" "<<endl;
        reverse(nums.begin() + indx + 1, nums.end());
        return;
    }
};