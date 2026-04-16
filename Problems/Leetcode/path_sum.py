# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def traverse_rec(node: TreeNode, target_sum: int) -> bool:
    target_sum -= node.val

    if node.left is None and node.right is None and target_sum == 0:
        return True
    
    print(target_sum)
    left_result = right_result = False
    if node.left is not None:
        left_result = traverse_rec(node.left, target_sum)
    if node.right is not None:
        right_result = traverse_rec(node.right, target_sum)
    return left_result or right_result
    

class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if root is None:
            return False
        return traverse_rec(root, targetSum)
        
        