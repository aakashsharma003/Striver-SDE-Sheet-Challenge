class Solution {
public:
   string helper(string str){
    int n = str.size();
    if(n == 1){
        return str == "0"?"1":"0";
    }
    if(n%2) str[n/2] = (str[n/2] == '0'? '1':'0'); 
    for(int i = 0;i < str.size()/2;i++){
        str[i] = (str[i] == '0'? '1': '0');
        str[n - 1 - i] = (str[n - 1 - i] == '0'? '1': '0');
        swap(str[i], str[n - 1 - i]);
    }
    return str;
   }


   string solve(string s, int n){
       if(n == 0) return s;
       s = s + "1" + helper(s);
       return solve(s, n - 1);
   }
    char findKthBit(int n, int k) {
        string ans = solve("0", n);
        return ans[k - 1];
    }
};