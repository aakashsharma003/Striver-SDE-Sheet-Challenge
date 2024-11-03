class Solution {
public:
   
    bool rotateString(string s, string goal) {
       int m = goal.size(), n = s.size();
       goal += goal;
       for(int i = 0;i < 2*m;i++){
        if(goal.substr(i, m) == s){
            return true;
        }
       }
       return false;
    }
};