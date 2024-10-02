class Solution {
    public int[] arrayRankTransform(int[] arr) {
        ArrayList<Integer>temp = new ArrayList<Integer>();
        for(var num: arr) temp.add(num);
        Collections.sort(temp);
        HashMap<Integer,Integer>mp = new HashMap<>();
        int rank = 1;
        for(var num: temp){
            if(mp.containsKey(num)) continue;
            mp.put(num, rank);
            rank++;
        }
        int n = arr.length;
        int []ans = new int[n];
        for(int i = 0;i < n;i++) ans[i] = mp.get(arr[i]);
        return ans;
    }
}