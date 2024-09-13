class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size(), q = queries.size();
        vector<int>pref(n, 0);
        pref[0] = arr[0];
        vector<int>ans(q, 0);
        for(int i = 1;i < n;i++){
           pref[i] = pref[i - 1] ^ arr[i];
        //    cout<<pref[i]<<endl;
        }
        for(int i = 0;i < q;i++){
            if(queries[i][0] > 0)
            ans[i] = pref[queries[i][0] - 1] ^ pref[queries[i][1]];
            else
            ans[i] = pref[queries[i][1]];

        }
        return ans;
    }
};