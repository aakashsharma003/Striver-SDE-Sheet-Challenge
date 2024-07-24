class Solution {
public:
    vector<int> sortJumbled(vector<int>& mp, vector<int>& nums) {
      sort(nums.begin(), nums.end(), [&](auto &n1, auto &n2){
        string s1 = to_string(n1);
        string s2 = to_string(n2);
        for(int i = 0;i < s1.size();i++){
            s1[i] = (char)(mp[s1[i] - '0'] + '0');
        }
        for(int i = 0;i < s2.size();i++){
            s2[i] = (char)(mp[s2[i] - '0'] + '0');
        }
         return stoi(s1) < stoi(s2);
      });
      
       return nums;
    }
};