class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int>mp;
        int cnt = 0, n = arr.size();
        for(auto num: arr){
            
            if(mp.find(k - (num%k + k)%k) != mp.end()){
            mp[k - (num%k + k)%k]--;
            if(!mp[k - (num%k + k)%k]) mp.erase(k - (num%k + k)%k);
              cnt++;
            }
            else if(num % k == 0 && mp.find(0) != mp.end()){
               mp[0]--;
               if(!mp[0]) mp.erase(0);
               cnt++;
            }
            else{
              if((num%k + k)%k == 0) mp[0]++;
              else
              mp[(num%k + k)%k]++;
            }
            cout<<cnt<<" "<<num<<endl;
        }
        cout<<cnt<<endl;
        return cnt == n/2;
    }
};