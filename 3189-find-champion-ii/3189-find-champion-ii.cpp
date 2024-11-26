class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indeg(n,0);
        
        for(auto &v: edges){
            indeg[v[1]]++;
        }
        
        
        int mini = INT_MAX, cnt = 1, champ;
        for(int node = 0;node < n;node++){
            if(indeg[node] < mini){
                cnt = 1;
                mini = indeg[node];
                champ = node;
            }
            else if(indeg[node] == mini) cnt++;
        }
        
        return cnt > 1 ? -1: champ; 
    }
};