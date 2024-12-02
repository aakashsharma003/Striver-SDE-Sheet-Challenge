class Solution {
public:
    int isPrefixOfWord(string s, string searchWord) {
        int n = s.size(), len = searchWord.size(), wdcnt = 1;
        for(int i = 0;i < n;i++){
            int j = i;
            while(j < n && s[j] != ' '){
                j++;
            }
            string pref = s.substr(i, len);
            if(pref == searchWord){
                return wdcnt;
            }
            wdcnt++;
            i = j;
        }
        return -1;
    }
};