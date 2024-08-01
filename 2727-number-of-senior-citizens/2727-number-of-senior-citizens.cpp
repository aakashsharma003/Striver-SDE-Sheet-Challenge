class Solution {
public:
    int countSeniors(vector<string>& arr) {
        int cnt = 0;
        for(int i = 0;i < arr.size();i++){
            // cout<<stoi(arr[i].substr(11,2))<<" ";
            if(stoi(arr[i].substr(11,2)) > 60){
                cnt++;
            }
        }
        return cnt; 
    }
};