class Solution {
public:
    void solve(int indx, vector<int>& arr, int target, vector<int>& temp,
               vector<vector<int>>& st) {
        int n = arr.size();
         if (target == 0) {
            
            st.push_back(temp);
            return;
        }
        if (indx == n)
            return;

        for (int i = indx; i < n; i++) {
            if(i > indx && arr[i-1] == arr[i])
                continue;
            if (arr[i] <= target) {
                temp.push_back(arr[i]);
                solve(i + 1, arr, target - arr[i], temp, st);
                temp.pop_back();
            }
        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // set<vector<int>> st;
        vector<int> temp;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target, temp, ans);
        return ans;
    }
};