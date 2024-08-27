class Solution {
    public boolean solve(int indx, String s, HashMap<String, Boolean> hmp, int dp[]) {
        if (indx >= s.length()) return true;
        if(dp[indx] != -1) return dp[indx] == 1? true: false;
        boolean flag = false;
        for (int i = indx; i < s.length(); i++) {
            String str = s.substring(indx, i + 1);
            if (hmp.containsKey(str)) {
                // System.out.println("str:" + str + i);
                flag = flag | solve(i + 1, s, hmp, dp);
            }
        }
        dp[indx] = flag?1:0;
        return flag;
    }

    public boolean wordBreak(String s, List<String> wordDict) {
        HashMap<String, Boolean> hmp = new HashMap<>();
        int dp[] = new int[301];
        Arrays.fill(dp, -1);
        for (var str : wordDict)
        hmp.put(str, true);
        return solve(0, s, hmp, dp);
    }
}