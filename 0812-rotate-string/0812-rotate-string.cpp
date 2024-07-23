class Solution {
public:
    bool rotateString(string s, string goal) {
       if(s.size() != goal.size()) return false; 
       int m = goal.size();
       goal += goal;
       int n = s.size();
       for(int i = 0;i < 2*m;i++){
        if(goal.substr(i, n) == s){
            return true;
        }
       }
       return false;   
    }
};