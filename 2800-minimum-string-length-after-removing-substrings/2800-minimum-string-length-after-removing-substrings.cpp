class Solution {
public:
    int minLength(string s) {
      stack<char>stk;
      for(auto ch: s){
        bool flag = true;
        if(!stk.empty() && stk.top() == 'A' && ch == 'B'){
            flag = false;
            stk.pop();
        }
        if(!stk.empty() && stk.top() == 'C' && ch == 'D'){
            flag = false;
            stk.pop();
        }
        if(flag)
        stk.push(ch);
       }
       return stk.size();  
    }
};