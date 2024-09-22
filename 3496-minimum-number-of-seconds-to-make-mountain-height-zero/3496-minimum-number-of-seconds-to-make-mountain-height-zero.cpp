class Solution {
public:
   // maine mid kitne time m tod skta hu
   long long againCheck(long long mid, int val){
    return val*(mid)*(mid + 1)/2;
   }
   long long innerCheck(long long time, int val, int h){
       long long  low = 0, high = h, mid;
       while(low <= high){
        mid = low + (high - low)/2;
        // mid todne mai kitna time lga
        long long curTime = againCheck(mid, val); 
        // long long curTime = 0; 
        // cout<<low<<" "<<high<<" "<<mid<<endl;
        if(curTime <= time) low = mid + 1;
        else high = mid - 1;
       }
     return high;
   }
//   []

    // t time mai possible skte ho ya nhi
    bool check(long long time, vector<int>&wt, int h){
        long long totaltoda = 0;
        for(auto it: wt){
            // mai itna tod skta hu t time mai 
            long long isnekitnatoda = innerCheck(time, it, h);
            // long long isnekitnatoda = 0;
            totaltoda += isnekitnatoda;
            if(totaltoda >= h){
             return true;
            }
        }
        return totaltoda >= h;
    }    

    long long binarySearch(long long low,long long high, vector<int>& wt, int h){
        long long  mid;
        while(low <= high){
            mid = low + (high - low)/2;
            // 
            bool t = check(mid, wt, h);
            if(t) high = mid - 1; 
            else low = mid + 1;
        }
        return low;
    }
    
    long long minNumberOfSeconds(int h, vector<int>& wt) {
        int n = wt.size();
       return binarySearch(1, 1e18, wt, h);  
    }
};