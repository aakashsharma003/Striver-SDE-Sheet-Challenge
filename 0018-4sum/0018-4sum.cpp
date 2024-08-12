class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>st;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0;i < n - 3;i++){
            for(int j = i + 1;j < n - 2;j++){
               int k = j + 1, l = n - 1;
               while(k < l){
                //  if(nums[i] >= target) break;
                 long long cursum = nums[i];
                 cursum += nums[k];
                 cursum += nums[l];
                 cursum += nums[j];
                 if(cursum < target) k++;
                 else if(cursum == target){ st.insert({nums[i], nums[j], nums[k], nums[l]});
                 k++;l--;
                //  break;
                 }
                 else l--;  
               }
            }
            
        }
        vector<vector<int>>ans(st.begin(), st.end());
        return ans;
    }
};