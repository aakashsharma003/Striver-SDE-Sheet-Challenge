#define ppi pair<long long, int>
#define MOD 1000000007
class Solution {
public:
    long long power(long long x, long long y, long long p) {
        long long res = 1; // Initialize result

        x = x % p; // Update x if it is more than or equal to p

        while (y > 0) {
            // If y is odd, multiply x with  
            //  the result
            if (y & 1)
                res = (res * x) % p;

            // y must be even now
            y = y >> 1; // y = y/2
            x = (x * x) % p;
        }
        return res;
         
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if(multiplier == 1) return nums;
        priority_queue<ppi, vector<ppi>, greater<ppi>> minhp;
        unordered_map<int, int> mp;
        long long maxi = 0, n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
            maxi = max((long long)nums[i], maxi);
        }
        for (int i = 0; i < nums.size(); i++) {
            minhp.push({nums[i], i});
        }
        while (k) {
            long long x = (minhp.top().first % MOD) * (multiplier % MOD);
            if (x > maxi) {
                break;
            }
            x %= MOD;
            long long y = minhp.top().second;
            minhp.pop();
            minhp.push({x, y});
            maxi = max(maxi, x);
            k--;
        }
        long long rem = k % n, div = k / n;
        // vector<long long> ans;
        // cout<<k<<" "<<rem<<endl;
        while (!minhp.empty()) {
            long long val = minhp.top().first;
            long long ind = minhp.top().second;
            long long mul = power(multiplier, div, MOD);
            mul = mul % (MOD);
            nums[ind] = ((val % MOD) * (mul % MOD)) % MOD;
            // cout<<nums[ind]<<" "<<mul<<endl;
            if (rem) {
                long long val = (((long long)nums[ind] % MOD) * (multiplier % MOD)) % MOD;

                nums[ind] = val % MOD;
                rem--;
            }
            minhp.pop();
        }

        return nums;
    }
};