class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int>x(m, -1);
        vector<int>y(n, -1);
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(matrix[i][j] == 0){
                    x[i] = 0;y[j] = 0; 
                }
            }
        }
        for(int i = 0;i < m;i++){
            if(x[i] == 0){
              for(int j = 0;j < n;j++){
                matrix[i][j] = 0;
              }
            }
        }
        for(int j = 0;j < n;j++){
            if(y[j] == 0){
              for(int i = 0;i < m;i++){
                matrix[i][j] = 0;
              }
            }
        }
        return;
    }
};