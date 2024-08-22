class Solution {
    public int findComplement(int num) {
        int ans = 0, i = 0, pow = 0, temp = num;
        while(num > 0){
             System.out.println(num);
            num = num>>1;
            pow++;   
        }
      
        // System.out.println(pow);
        // System.out.println(num + " " + ((1 << pow) - 1));
        return temp ^ ((1 << pow) - 1);
    }
}