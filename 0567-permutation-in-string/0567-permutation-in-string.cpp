class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end());
        // unordered_map<char, int>mp1, mp2;
        // for(auto it: s1) mp1[it]++;
        int n = s1.size();
        for(int i = 0;i <= min(s2.size() - n, s2.size() - 1);i++){
           string str = s2.substr(i, n);
           sort(str.begin(), str.end());
        //    cout<<str<<endl;
           if(str == s1) return true;
        }
        return false;
    }
};