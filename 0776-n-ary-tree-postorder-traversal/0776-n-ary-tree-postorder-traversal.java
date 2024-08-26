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
    public List<Integer> postorder(Node root) {
        List<Integer> ans = new ArrayList<Integer>();
        if(root == null) return ans;
        Stack<Node> stk = new Stack<Node>();
        stk.push(root);
        while(!stk.isEmpty()){
            int size = stk.size(); 
            for(int i = 0;i < size;i++){
                Node curnode = stk.pop();
                for(var child: curnode.children)
                    if(child != null) stk.push(child);
                 ans.add(curnode.val);
            }
        }
        Collections.reverse(ans);
        return ans;
    }
}