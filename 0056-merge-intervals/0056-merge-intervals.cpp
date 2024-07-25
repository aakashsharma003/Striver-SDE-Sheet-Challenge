class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        for(int i = 1;i < v.size();i++){
            if(v[i][0] <= v[i - 1][1]){
              if(v[i][1] >= v[i - 1][1]) {
                 v[i][0] = v[i - 1][0]; 
                 v[i][1] = v[i][1];
             }
              else{
               v[i][0] = v[i - 1][0];
               v[i][1] = v[i - 1][1];
              } 
            }
        }
        
        set<vector<int>>st;
        int i;
        for(i = 1;i < v.size();i++){
          while(i < v.size() && v[i - 1][0] == v[i][0]){
            i++;
          }
          st.insert(v[i - 1]);        
        }
        st.insert(v[v.size() - 1]);


        vector<vector<int>>ans(st.begin(), st.end());
        return ans;
    }
};