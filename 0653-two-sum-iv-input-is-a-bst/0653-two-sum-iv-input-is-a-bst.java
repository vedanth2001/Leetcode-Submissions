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
public class BSTiterator{

    Stack<TreeNode> st = new Stack<TreeNode>();
    boolean reverse;
    public BSTiterator(TreeNode root, boolean isReverse){
        reverse = isReverse;
        pushAll(root);
    }
    private void pushAll(TreeNode root){
        while(root != null) {st.push(root);
        if(!reverse){
            root = root.left;
        }
        else{
            root = root.right;
        }
        }
        return;
    }
    public int next(){
        TreeNode curr = st.pop();
        if(reverse) pushAll(curr.left);
        else{
            pushAll(curr.right);
        }
        return curr.val;
    }

 }
class Solution {
    public boolean findTarget(TreeNode root, int k) {
        if(root == null) return false;
        BSTiterator l = new BSTiterator(root, false);
        BSTiterator r = new BSTiterator(root, true);

        int i = l.next();
        int j = r.next();
        while(i<j){
            if(i + j == k) return true;
            if(i + j > k) j = r.next();
            else i = l.next();
        }
        return false;
    }
}