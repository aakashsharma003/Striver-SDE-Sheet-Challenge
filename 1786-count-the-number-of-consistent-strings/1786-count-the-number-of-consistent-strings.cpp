class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool>freq(26, false);
        for(auto ch: allowed) freq[ch - 'a'] = true;
        int cnt = 0;
        for(auto str: words){
            bool isConsistent = true;
            for(auto ch: str){
               if(!freq[ch - 'a']){
                isConsistent = false;
                break;
               }
            }
            if(isConsistent) cnt++;
        }
        return cnt;
    }
};