#define ppi pair<pair<int, int>, int> 

class Compare
{
public:
    bool operator() (auto p1, auto p2)
    {
        return p1.second < p2.second;
    }
};




class Solution {
public:
   bool isValidIndx(int i, int j, int m, int n){
     if(i < 0 || j < 0 || i >= m || j >= n) return false;
     return true;
   }
    bool findSafeWalk(vector<vector<int>>& grid, int h) {
        int m = grid.size(), n =  grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        priority_queue<ppi, vector<ppi>, Compare>pq;
        if(grid[0][0]) h--;
        pq.push({{0,0}, h});
        vis[0][0] = true;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        while(!pq.empty()){
           auto [pos, h] = pq.top();
           auto [x, y] = pos;
        //    cout<<x<<" "<<y<<" "<<h<<endl;
           pq.pop();
        //    if(h <= 0){
        //        return false;
        //    }
           if(x == m - 1 && y == n - 1 && h >= 1){
             return true;
           }
    
           for(int i = 0;i < 4;i++){
                int curx = x + dx[i];
                int cury = y + dy[i];
                if(isValidIndx(curx, cury, m, n) && !vis[curx][cury]){
                   
                    if(grid[curx][cury]){
                        if(h - 1 >= 1){ 
                             vis[curx][cury] = true;
                            pq.push({{curx, cury}, h - 1});
                            }
                    }
                    else{
                       vis[curx][cury] = true;
                      pq.push({{curx, cury}, h});
                    }
                }
            }
        }
        
        return false;
    }
};