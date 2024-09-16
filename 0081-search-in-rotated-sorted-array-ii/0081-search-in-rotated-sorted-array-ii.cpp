class Solution {
public:
    bool solve(vector<int>& arr, int &target){
        int low = 0, high = arr.size() - 1, mid;
        while(low <= high){
            mid = low + (high - low)/2;
            if(target == arr[mid]) return true;
             if(arr[low] == arr[mid] && arr[mid] == arr[high]){
                low++;
                high--;
                continue;
            }
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
        return false;
    }
    bool search(vector<int>& nums, int target) {
        return solve(nums, target);   
    }
};