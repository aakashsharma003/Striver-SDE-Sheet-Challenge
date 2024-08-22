class Solution {
    public int findComplement(int num) {
        int ans = 0, i = 0, pow = 0, temp = num;
        while(num > 0){
            num = num>>1;
            pow++;   
        }
        return temp ^ ((1 << pow) - 1);
    }
}