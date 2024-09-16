class Solution {
public:
    int getElement(vector<int>& arr, int &target){
        int low = 0, high = arr.size() - 1, mid;
        while(low <= high){
            mid = low + (high - low)/2;
            if(target == arr[mid]) return mid;
            else if(arr[mid] <= arr[high]){
                  if(arr[mid] <= target && target <= arr[high])
                   low = mid + 1;
                  else
                   high = mid - 1;
               
            }
            else{
                 if(target <= arr[mid] && arr[low] <= target)
                    high = mid - 1;
                else
                   low = mid + 1;
             
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return getElement(nums, target);
    }
};