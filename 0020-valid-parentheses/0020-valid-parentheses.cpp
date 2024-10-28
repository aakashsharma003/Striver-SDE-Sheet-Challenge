class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for(auto ch: s){
        
            if(!stk.empty() && (ch == '}' || ch == ')' || ch == ']')){
                if(ch == '}' && stk.top() != '{')  return false;
                if(ch == ')' && stk.top() != '(')  return false;
                if(ch == ']' && stk.top() != '[')  return false;
                stk.pop();
            }
            else
            stk.push(ch);
        }
        return stk.empty();
    }
};