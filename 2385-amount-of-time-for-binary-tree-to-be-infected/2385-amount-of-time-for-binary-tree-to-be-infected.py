# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def timeFromNodeK(self, root: Optional[TreeNode]):
        if not root:
            return 0
        
        if not root.left and not root.right:
            return 0
        
        left_subtree_time = self.timeFromNodeK(root.left)
        right_subtree_time = self.timeFromNodeK(root.right)

        return 1 + max(left_subtree_time, right_subtree_time)

    def distFromRootNode(self, root: Optional[TreeNode], infected: int) -> int:
        # if distance is -1, node is not present, else the node is present at distance k
        # returns integer (-1 <= x <= limit)
        if not root:
            return -1
        if root.val == infected:
            return 0
        
        dist_left = self.distFromRootNode(root.left, infected)
        if dist_left != -1:
            return 1 + dist_left
        dist_right = self.distFromRootNode(root.right, infected)
        if dist_right != -1:
            return 1 + dist_right
        
        return -1

    def amountOfTimeHelper(self, root: Optional[TreeNode], start: int) -> tuple:
        if not root:
            return 0, -1
        if root.val == start:
            return self.timeFromNodeK(root), 0

        left_time, left_subtree_distance = self.amountOfTimeHelper(root.left, start)
        if left_subtree_distance >= 0: #infected node is at left subtree
            right_subtree_time = self.timeFromNodeK(root.right)
            if root.right:
                right_subtree_time = 1 + right_subtree_time
            linear_time_right = right_subtree_time + left_subtree_distance + 1
            return max(left_time, linear_time_right), left_subtree_distance + 1
        
        right_time, right_subtree_distance = self.amountOfTimeHelper(root.right, start)
        if right_subtree_distance >= 0: #infected node is at right subtree
            left_subtree_time = self.timeFromNodeK(root.left)
            if root.left:
                left_subtree_time = 1 + left_subtree_time
            linear_time_left = left_subtree_time + right_subtree_distance + 1
            return max(right_time, linear_time_left), right_subtree_distance + 1
        return 0, -1
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        return self.amountOfTimeHelper(root, start)[0]
