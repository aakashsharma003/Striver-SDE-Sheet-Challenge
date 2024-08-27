/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean getPath(TreeNode node, List<Integer>path, TreeNode search){
      if(node == null) return false;
      if(node.val == search.val){
        path.add(node.val); 
        return true;
        }
      path.add(node.val);
      boolean left = getPath(node.left, path, search);
      boolean right = getPath(node.right, path, search);
      if(left || right) return true;
      path.remove(path.size() - 1);
      return false;
    } 
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        List<Integer>ls1 = new ArrayList<Integer>();
        List<Integer>ls2 = new ArrayList<Integer>();
        getPath(root, ls1, p);
        getPath(root, ls2, q);
        // System.out.println(ls1.size());
        // System.out.println(ls2.size());
        int i = 0, j = 0;
        TreeNode ans = null;
        while(i < ls1.size() && j < ls2.size()){
            if(ls1.get(i).equals(ls2.get(j))) ans = new TreeNode(ls2.get(j));
            i++;
            j++;
        }
        return ans;
    }
}