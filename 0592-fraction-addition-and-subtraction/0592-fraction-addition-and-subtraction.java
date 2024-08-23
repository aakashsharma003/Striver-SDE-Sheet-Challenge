class Solution {
    static int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        else
            return gcd(b, Math.abs(a - b));
    }
    public String fractionAddition(String exp) {
        int den = 1, num = 0;
         if(exp.charAt(0) != '-'){
          exp = '+' + exp;
        }
        System.out.println(exp);
        for(int i = 0;i < exp.length() - 1;i++){
            if(exp.charAt(i) == '/'){
                int val = 0, j = i + 1;
                while(j < exp.length() ){
                    if(exp.charAt(j) == '+' || exp.charAt(j) == '-') break;
                    System.out.println((int)(exp.charAt(j) - '0'));
                    val = val*10 + (int)(exp.charAt(j) - '0');
                    j++;
                }
                den = den*val;
            }
        }
    
        for(int i = 0;i < exp.length() - 3;){
            char op = exp.charAt(i);
            System.out.println(i);
            int numr = 0, j = i + 1;
            while(j < exp.length() && exp.charAt(j) != '/'){
                numr = numr*10 +  exp.charAt(j) - '0';
                j++;
            }
            if(exp.charAt(j) == '/')
            j++;
            int d = 0;
            while(j < exp.length()){ 
                if(exp.charAt(j) == '+' || exp.charAt(j) == '-') break;
                d = d*10 + (exp.charAt(j) - '0');
                j++;
            }
            int val = (den / d) * numr;
           
            num = (op == '+' ? num + val : num - val);
             i = j;
        }
        int div = gcd(num, den);
        num /= div;
        den /= div;
        String ans = "";
        ans += num;
        ans += '/';
        ans = (num == 0 ? ans + 1: ans + den);
       return ans; 
    }
}