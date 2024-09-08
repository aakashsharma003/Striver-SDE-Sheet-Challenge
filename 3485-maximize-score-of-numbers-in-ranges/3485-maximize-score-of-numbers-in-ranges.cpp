class Solution {
public:
   int maxi = INT_MAX;
   bool isPossible(int score, vector<int>& start, int d){
       int val = start[0];
       for(int i = 1;i < start.size();i++){
           val += score;
           if(val > start[i] + d) return false;
           val = max(val, start[i]);
       }
       return true;
   }
//    0, 3,6, 9
   



    int maxPossibleScore(vector<int>& start, int d) {
        int n = start.size();
        sort(start.begin(), start.end());
        for(int i = 1;i < n;i++)
        maxi = min(start[i] - start[i - 1], maxi);
         int low = 0, high = INT_MAX;
        while(low < high){
           int mid = low + (high - low)/2;
           cout<<mid<<" ";
           if(isPossible(mid, start, d)){
             maxi = max(mid, maxi);
             low = mid + 1;
           }
           else
            high = mid;
        }
        return maxi;
    }
};