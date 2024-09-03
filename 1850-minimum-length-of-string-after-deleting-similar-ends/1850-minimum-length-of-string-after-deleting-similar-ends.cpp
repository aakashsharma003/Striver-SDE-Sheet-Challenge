class Solution {
public:

    int minimumLength(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while(i < j && i < n && j < n){
            if(s[i] == s[j]){
                int k = j;
                cout<<j<<" "<<i<<endl;
                while(s[k] == s[j] && j > i)j--;

                k = i;
                while(s[k] == s[i] && j >= i) i++;
                cout<<j<<" "<<i<<endl;
            }
            else break;
        }
        return j - i + 1;
    }
};