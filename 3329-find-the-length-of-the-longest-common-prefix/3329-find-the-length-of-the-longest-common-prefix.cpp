class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<string>st1, st2;
        for(auto num: arr1){
            string str = to_string(num), pref = "";
            for(auto ch: str){
                pref += ch; 
                st1.insert(pref);
            }
        }
        int ans = 0;
        for(auto num: arr2){
            string str = to_string(num), pref = "";
            int len = 0;
            for(auto ch: str){
                pref += ch; 
                len++;
                if(st1.find(pref) != st1.end()) ans = max(ans, len); 
            }
        }
        return ans;
    }
};