class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>st;
        unordered_map<long long, int>mp;
        int n = nums.size();
        for(int i = 0;i < n - 2;i++){
            for(int j = i + 1;j < n - 1;j++){
              for(int k = j + 1;k < n;k++){
                long long val = target;
                val -= nums[i];
                val -= nums[j];
                val -= nums[k];
                  if(mp.find(val) != mp.end()){
                    vector<int>temp({nums[i], nums[j], nums[k], target - (nums[i] + nums[j] + nums[k])});
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                  }
                  mp[nums[k]]++; 
              }
              mp.clear();
            }
            
        }
        vector<vector<int>>ans(st.begin(), st.end());
        return ans;
    }
};