class Solution {
public:
   void reverse(int l,int r, vector<int> &arr){
     int n = r - l + 1;
      for(int i = 0;i < n/2;i++){
        swap(arr[i + l], arr[n - 1 - i + l]);
      }
     return;
   }

    void nextPermutation(vector<int>& nums) {
        int indx = -1, n = nums.size();
        for(int i = n - 1;i >= 1;i--){
            if(nums[i-1] < nums[i]){
                indx = i - 1;
                break;
            }
        }
        if(indx == -1){
             reverse(0, n - 1, nums);
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
        reverse(indx + 1, n - 1, nums);
        return;
    }
};