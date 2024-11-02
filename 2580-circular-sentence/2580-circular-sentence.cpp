class Solution {
public:
    bool isCircularSentence(string str) {
      for(int i = 0;i < str.size();i++){
        int j = i;
        char lastchar = str[i];
        while(j < str.size() && str[j] != ' '){
           lastchar = str[j];
           j++;
        }
    
        while(j < str.size() && str[j] == ' '){
         j++;
        }

        if(j == str.size()){
            return lastchar == str[0];
        }
        cout<<lastchar<<" "<<str[j]<<endl;
        if(lastchar != str[j]) return false;
        i = j - 1;
      }
      return true;  
    }
};