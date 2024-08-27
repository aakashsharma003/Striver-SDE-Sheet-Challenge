class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Stack<Integer>stk = new Stack<>();
        int n = nums1.length, m =  nums2.length;
        int []ans = new int[n];
        stk.push(-1);
        for(int j = 0;j < n;j++){
            for(int i = m - 1;i >= 0;i--){
                if(stk.size() > 0){
                   int top = stk.peek();
                if(nums2[i] > nums1[j]){
                  stk.pop();
                  stk.push(nums2[i]);
                }
                else if(nums2[i] == nums1[j]) break;

                }
            }
            if(stk.size() > 0){
            ans[j] = stk.pop();
            stk.push(-1);
            }
            
        }
        return ans;
    }
}