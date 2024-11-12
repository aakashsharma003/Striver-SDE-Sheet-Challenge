class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n = nums.size();
       int left = 1,right = 1;
        vector<int>lft(n);
        vector<int>rght(n);
        lft[0] = 1;
        rght[0] = 1;  
        for(int i = 1;i < n;i++){
            left *= nums[i-1];
            lft[i] = left;

            right *= nums[n-i];
            rght[i] = right;
        }
        reverse(rght.begin(),rght.end());
        for(int i = 0;i < n;i++)
        nums[i] = lft[i]*rght[i];
        return nums;
    }
};