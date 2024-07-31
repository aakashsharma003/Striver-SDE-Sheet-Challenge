class Solution {
public:
     void solve(int indx, vector<int> &v, set<vector<int>>&temp){
      if(indx == v.size()){
        temp.insert(v);
        return;
      }
      for(int i = indx;i < v.size();i++){
         swap(v[i], v[indx]);
         solve(indx + 1, v, temp);
         swap(v[i], v[indx]);
      }
      return;
   }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>>st;
        solve(0, nums, st);
        vector<vector<int>>ans(st.begin(), st.end());
        return ans;
    }
};