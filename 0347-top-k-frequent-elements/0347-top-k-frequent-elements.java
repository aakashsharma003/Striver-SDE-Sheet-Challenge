class Solution {

    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>((a, b) -> a.getValue() - b.getValue());
        for(var num: nums){
          mp.put(num, mp.getOrDefault(num, 0) + 1);
        }
        for(Map.Entry<Integer,Integer> entry: mp.entrySet()){
           pq.add(entry);
           if(pq.size() > k){
            pq.remove();
           }
        }
        int ans[] = new int[k];
        while(k > 0){
            // System.out.println(pq.peek().getValue() +" "+  pq.peek().getKey());
            ans[k - 1] = pq.poll().getKey();
            k--;
        }

        return ans;

    }
}