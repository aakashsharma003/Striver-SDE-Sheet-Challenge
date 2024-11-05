class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size(), m = nums1.size();
        unordered_map<int, int>nge;
        stack<int>stk;
        nge[nums2[n - 1]] = -1;
        stk.push(nums2[n - 1]);
        for(int i = n - 2;i >= 0;i--){
            if(nums2[i] > stk.top()){
              while(!stk.empty() && nums2[i] > stk.top()){
                stk.pop();
              }
            }
            if(stk.empty()){
             nge[nums2[i]] = -1;   
             stk.push(nums2[i]);
              continue;    
            }
             nge[nums2[i]] = stk.top();
            stk.push(nums2[i]);
        }
        vector<int>ans(m);
        for(int i = 0;i < m;i++){
            ans[i] = nge[nums1[i]];
        }
        return ans;
    }
};