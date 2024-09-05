class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        vector<int>ans;
        int sum = 0;
        for(auto it: rolls) sum += it;
        int missingSum = mean*(n + m) - sum;
        int val = missingSum / n;
        int rem = missingSum % n;
        if(sum >= mean*(n + m) || val > 6 || val == 0) return ans;
        else{
            ans.resize(n);
            cout<<n<<" "<<val<<endl;
            fill(ans.begin(), ans.end(), val);
            for(int i = 0;i < n;i++){
                int j = i;
                while(rem != 0 && ans[j] < 6){
                   ans[j] += 1;
                   rem--;
                }
            }
            if(rem > 0){ 
                vector<int>temp;
                return temp;
            }
            return ans;
        }
    }
};