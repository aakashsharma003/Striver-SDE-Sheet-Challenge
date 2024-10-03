class Solution {
public:
    bool isAlmostEquals(int n1, int n2){
        if(n1 == n2) return true;
        string str1 = to_string(n1);
        string str2 = to_string(n2);
        
         for(int i = 0;i < str1.size();i++){
            for(int j = i + 1;j < str1.size();j++){
                 swap(str1[i], str1[j]);
                 int num1 = stoi(str1), num2 = stoi(str2);
                 if(num1 == n2) return true;
                 swap(str1[i], str1[j]);
            }
         }
           for(int i = 0;i < str2.size();i++){
            for(int j = i + 1;j < str2.size();j++){
                 swap(str2[i], str2[j]);
                 int num1 = stoi(str1), num2 = stoi(str2);
                 if(num1 == num2) return true;
                 swap(str2[i], str2[j]);
            }
         }
         return false;
    }
   
    int countPairs(vector<int>& nums) {
        int ans = 0;
        for(int i = 0;i < nums.size();i++){
            for(int j = i + 1;j < nums.size();j++){
                if(isAlmostEquals(nums[i], nums[j])){
                  ans++;
                }
            }
        }
        return ans;
    }
};