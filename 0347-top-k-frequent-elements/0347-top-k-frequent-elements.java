class Solution {

    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        PriorityQueue<Map.Entry<Integer, Integer>> minhp = new PriorityQueue<>((a, b) -> a.getValue() - b.getValue());
        for(var num: nums){
          mp.put(num, mp.getOrDefault(num, 0) + 1);
        }
        for(Map.Entry<Integer,Integer> entry: mp.entrySet()){
           minhp.add(entry);
           if(minhp.size() > k){
            minhp.remove();
           }
        }
        int ans[] = new int[k];
        while(k > 0){
            // System.out.println(minhp.peek().getValue() +" "+  minhp.peek().getKey());
            ans[k - 1] = minhp.poll().getKey();
            k--;
        }

        return ans;

    }
}