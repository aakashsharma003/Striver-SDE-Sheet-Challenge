class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<vector<int>> fd = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0, xp = 0, yp = 0, res = 0;
        unordered_map<int, unordered_set<int>> ob;
        for(int i = 0; i < obstacles.size(); i++){
            ob[obstacles[i][0]].insert(obstacles[i][1]);
        }
        for(int i : commands){
            if(i == -2) d = (d + 3) % 4;
            else if(i == -1) d = (d + 1) % 4;
            else{
                for(int j = 0; j < i; j++){
                    if(!ob[xp + fd[d][0]].empty() && ob[xp + fd[d][0]].contains(yp + fd[d][1]))break;
                    xp += fd[d][0];
                    yp += fd[d][1];
                }
                res = max(res, xp * xp + yp * yp);
            }
        }
        return res;
    }
};