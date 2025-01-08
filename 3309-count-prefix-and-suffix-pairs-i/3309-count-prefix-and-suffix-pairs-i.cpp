class Solution {
public:
   int ans = 0;
  void KMP(string pat, string txt){
   int n = txt.length();
   int m = pat.length();
  vector<int>lps(m);
  fillLPS(pat,lps);
  int i = 0, j = 0;
      int cnt = 0;
      set<int>st;
  while(i < n){
  	if(pat[j] == txt[i]){ i++; j++;}
  	if(j == m){ st.insert(i - j);j = lps[j - 1];}
  	else if(i < n && pat[j] != txt[i]){
  		if(j == 0){i++;}
  		else{
  			j = lps[j - 1];
  		}
  	}
  }
  if(st.find(0) != st.end() && st.find(n - m) != st.end()){
      ans++;
  }    
}

void fillLPS(string str, vector<int>&lps){
    
    int n = str.length(), len = 0;
    lps[0] = 0;
    int i = 1;
	while(i < n){
		if(str[i] == str[len]){
			len++;
			lps[i] = len;
			i++;
		}
		else{
			if(len == 0){
				lps[i] = 0;
				i++;
			}
			else{
				len = lps[len - 1];
			}
		}
	}
}
    int countPrefixSuffixPairs(vector<string>& words) {
      
        for(int i = 0;i < words.size();i++){
            for(int j = i + 1;j < words.size();j++){
                // if(i < j){
                    KMP(words[i], words[j]);
                // }
            }
        }
        return ans;
    }
};