class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
         for(int j = 0;j < n/2;j++){
          swap(mat[j], mat[n - 1 - j]);
        }

        // transpose
        for(int i = 0;i < n;i++){
          for(int j = i + 1;j < n;j++){
            swap(mat[i][j], mat[j][i]);
          }  
        }
       
        return;
    }
};