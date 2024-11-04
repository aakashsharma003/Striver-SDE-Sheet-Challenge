class Solution {
public:
    string compressedString(string word) {
        string cmp = "";
        for(int i = 0;i < word.size();i++){
            int j = i, cnt = 0;
            while(j < word.size() && word[i] == word[j]){
                j++;
                cnt++;
            }
            cout<<cnt<<endl;
            while(cnt >= 9){
                cnt -= 9;
                cmp += to_string(9);
                cmp += word[i];
            }
            if(cnt){
                cmp += to_string(cnt);
                cmp += word[i];
                cnt = 0;
            }
            i = j - 1;
        }
        return cmp;
    }
};