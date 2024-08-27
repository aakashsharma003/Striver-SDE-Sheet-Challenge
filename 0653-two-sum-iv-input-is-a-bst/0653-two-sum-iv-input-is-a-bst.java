/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean solve(TreeNode root, HashMap<Integer, Boolean>mp, int k){
        if(root == null) return false;
        // if(root.val > k) return false;
        if(mp.containsKey(k - root.val) == true) return true;
        mp.put(root.val, true);
        boolean left = solve(root.left, mp, k);
        boolean right = solve(root.right, mp, k);
        if(left || right) return true;
        return false;
    }
    public boolean findTarget(TreeNode root, int k) {
        HashMap<Integer, Boolean>mp = new HashMap<>();
         return solve(root, mp, k);
    }
}