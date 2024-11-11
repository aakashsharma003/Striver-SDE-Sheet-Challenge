class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
         vector<bool> isPrime(1000, true);
        for(int i=2; i*i<=1000; ++i){
            if(!isPrime[i]) continue;
            for(int j=i*i; j<1000; j += i)
                isPrime[j] = false;
        }

        vector<int> primes;
        for(int i=0; i<1000; ++i) if(isPrime[i]) primes.push_back(i);

        auto f = [&](int val, int prev){
            if(val == 2 || val-2 <= prev) return 0;

            int l = 0, h = primes.size()-1;
            while(l <= h){
                int mid = (l + h) >> 1;
                if(primes[mid] >= val || val - primes[mid] <= prev)
                    h = mid - 1;
                else l = mid + 1;
            }
            return primes[h];
        };
        
        nums[0] -= f(nums[0], -1e9);
        for(int i=1; i<nums.size(); ++i){
            nums[i] -= f(nums[i], nums[i-1]);
            if(nums[i] <= nums[i-1]) return false;
        }
        return true;
    }
};