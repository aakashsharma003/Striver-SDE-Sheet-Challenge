class Solution {
public:
   void solve(int indx, vector<int> &v, vector<vector<int>>&temp){
      if(indx == v.size()){
        temp.push_back(v);
        return;
      }
      for(int i = indx;i < v.size();i++){
         swap(v[i], v[indx]);
         solve(indx + 1, v, temp);
         swap(v[i], v[indx]);
      }
      return;
   }
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>>ans;
       solve(0, nums, ans);
       return ans;            
    }
};