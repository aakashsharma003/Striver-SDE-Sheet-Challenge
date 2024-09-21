class Solution {
public:
    void solve(string str, int n, vector<int> &ans){
        if(str != "" && stoi(str) > n) return;
        // cout<<str<<endl;
        int num = stoi(str);
        ans.push_back(num);
        for(char ch = '0';ch <= '9';ch++){
            str.push_back(ch);
            solve(str, n, ans);
            str.pop_back();
        }
        return;
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        string str = "";
         for(char ch = '1';ch <= '9';ch++){
            str.push_back(ch);
             solve(str, n, ans);
            str.pop_back();
        }
       return ans;
    }
};