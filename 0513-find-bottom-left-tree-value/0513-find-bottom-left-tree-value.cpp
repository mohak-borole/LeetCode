/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int max_height = 0;
    int leftMost = NULL;
    void recursion(TreeNode* root , int height) {
         if(root != NULL) {
             height++;
             if(max_height < height) {
                 max_height = height;
                 leftMost = root->val;
             }
             recursion(root->left , height);
             recursion(root->right , height);
         }
    }
    
    int findBottomLeftValue(TreeNode* root) {
        max_height = 0;
        recursion(root , 0);
        return leftMost;
    }
};