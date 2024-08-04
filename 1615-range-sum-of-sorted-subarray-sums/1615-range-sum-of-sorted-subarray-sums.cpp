class Solution {
public:
    static const int MOD = 1000000007;
    
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // Find the maximum possible sum
        int maxSum = 0;
        for (int num : nums) {
            maxSum += num;
        }
        
        // Count the frequency of each sum
        vector<int> count(maxSum + 1, 0);
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                count[sum]++;
            }
        }
        
        // Calculate prefix sum of frequencies
        for (int i = 1; i <= maxSum; i++) {
            count[i] += count[i - 1];
        }
        
        long long result = 0;
        for (int sum = 1, k = 1; sum <= maxSum; sum++) {
            while (k <= count[sum]) {
                if (k >= left && k <= right) {
                    result = (result + sum) % MOD;
                }
                k++;
            }
        }
        
        return static_cast<int>(result);
    }
};