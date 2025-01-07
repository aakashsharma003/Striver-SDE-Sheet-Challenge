class Solution {
public:
    int findContentChildren(vector<int>& s, vector<int>& g) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int l = 0, r = 0;
        while(l < s.size() && r < g.size()){
          if(g[r] >= s[l]) l++;
          r++;
        }
        return l;
    }
};