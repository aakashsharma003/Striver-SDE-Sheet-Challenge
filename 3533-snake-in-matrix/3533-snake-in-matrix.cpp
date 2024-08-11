class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& cmd) {
        int i = 0, j = 0, cnt = 0;
        vector<vector<int>>pos(n, vector<int>(n));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                pos[i][j] = cnt;
                cnt++;
            }
        }
        for(int k = 0;k < cmd.size();k++){
            if(cmd[k] == "UP") i--;
            else if(cmd[k] == "DOWN") i++;
            else if(cmd[k] == "LEFT") j--;
            else j++;
        }
        return pos[i][j];
        // cout<<i<<" "<<j<<endl;
        // return 0;
    }
};