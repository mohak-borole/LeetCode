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
    int diameter;
    private int help(TreeNode root) {
        if(root == null) return 0;
        int left = help(root.left);
        int right = help(root.right);
        diameter = Math.max(diameter , left+right);
        return Math.max(left , right) +1;
    }
    
    public int diameterOfBinaryTree(TreeNode root) {
        diameter = 0;
        help(root);
        return diameter;
    }
}