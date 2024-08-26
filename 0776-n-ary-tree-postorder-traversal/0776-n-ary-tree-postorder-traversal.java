/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public void solve(Node curr, List<Integer> ls){
        for(var child: curr.children)
            if(child != null) solve(child, ls);

        ls.add(curr.val);
        return;
    }

    public List<Integer> postorder(Node root) {
        List<Integer> ans = new ArrayList<Integer>();
        if(root == null) return ans;
        solve(root, ans);
        return ans;
    }
}