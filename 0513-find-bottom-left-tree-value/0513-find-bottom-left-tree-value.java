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
    int max_height = 0;
    int leftMost = 0;
    
    private void recursion(TreeNode root , int height) {
        if(root != null) {
            height++;
            if(max_height < height) {
                max_height = height;
                leftMost = root.val;
            }
            recursion(root.left , height);
            recursion(root.right , height);
        }
    }
    
    public int findBottomLeftValue(TreeNode root) {
        max_height = 0;
        recursion(root , 0);
        return leftMost;
    }
}