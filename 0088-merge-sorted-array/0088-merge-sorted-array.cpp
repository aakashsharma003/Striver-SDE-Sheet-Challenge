class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       vector<int>ans(m + n, 0);
       int i = 0, j = 0, k = 0;
       while(i < m && j < n){
         if(nums1[i] < nums2[j]){
            ans[k] = nums1[i];
            i++;
         }
         else{
            ans[k] = nums2[j];
            j++;
         }
         k++;
       }
    //    cout<<i<<" "<<j<<endl;
       while(k < m + n && j < n){
        ans[k] = nums2[j];
        j++;
        k++;
       }
        while(k < m + n && i < m ){
        ans[k] = nums1[i];
        i++;
        k++;
       }
       for(int i = 0;i < m + n;i++)
        nums1[i] = ans[i]; 
    //    cout<<ans[i]<<" ";
       return;
    }
};