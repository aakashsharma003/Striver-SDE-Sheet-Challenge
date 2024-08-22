class Solution {
    public int romanToInt(String s) {
        HashMap<Character, Integer> mp = new HashMap<>();
        mp.put('I', 1);
        mp.put('V', 5);
        mp.put('X', 10);
        mp.put('L', 50);
        mp.put('C', 100);
        mp.put('D', 500);
        mp.put('M', 1000);
         int ans = 0, n = s.length();
         boolean isX = false,isI = false, isC = false;  
        for(int i = n - 1;i >= 0;i--){
              char key = s.charAt(i);
              int val = mp.get(key);
              if(key == 'V' || key == 'X') isI = true;
              if(key == 'L' || key == 'C') isX = true;
              if(key == 'D' || key == 'M') isC = true;
              if(key == 'I' && isI){ ans -= val; continue;}
            if(key == 'X' && isX){ ans -= val; continue;}
            if(key == 'C' && isC){ ans -= val; continue;}
              ans += val;
        }
        return ans;
    }
}