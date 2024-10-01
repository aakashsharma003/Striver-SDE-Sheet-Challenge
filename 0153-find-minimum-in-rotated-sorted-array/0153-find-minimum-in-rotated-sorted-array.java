class Solution {
    public int findMin(int[] nums) {
         int low = 0, high = nums.length - 1;
        int mini = Math.min(nums[low], nums[high]);
        while(low <= high){

            int mid = low + (high - low)/2;
            if(nums[mid] <= nums[high]){
               high = mid - 1;
               mini = Math.min(nums[mid], mini);
            }
            else
               low = mid + 1;
        }
        return mini;
    }
}