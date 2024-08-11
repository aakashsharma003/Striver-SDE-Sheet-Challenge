class Solution {
public:
    int cnt = 0;
    int solve(int node,int parent, vector<int>adj[]){
        int size = 1;
        int prevsize = -1;
        bool isSizeSame = true;
        for(int i = 0;i < adj[node].size();i++){
            if(adj[node][i] == parent) continue;
            else{
               int newsize = solve(adj[node][i], node, adj);
                if(prevsize == -1) prevsize = newsize;
                size += newsize;
                if(prevsize != newsize){
                    isSizeSame = false;
                }
            }
        }
        if(isSizeSame) cnt++;
        return size;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>adj[n + 1];
        for(int i = 0;i < n;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        solve(0,-1, adj);
        return cnt;
    }
};