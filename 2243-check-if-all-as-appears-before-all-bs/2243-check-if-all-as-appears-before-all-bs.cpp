class Solution {
public:
    bool checkString(string s) {
        bool flag = true;
        stack<int>st;
        for(auto ch: s){
            if(ch == 'a' && !st.empty() && st.top() == 'b'){
              return false;
            }
            else
            st.push(ch);
        }
        return true;
    }
};