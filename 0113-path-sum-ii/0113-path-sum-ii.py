# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def pathSum(self, root, targetSum):
        """
        :type root: Optional[TreeNode]
        :type targetSum: int
        :rtype: List[List[int]]
        """
        ans = []
        def dfs(node , target , path):
            if node is None :
                return 
            path.append(node.val)

            if node.left is None and node.right is None:
                if target == node.val:
                    ans.append(path[:])
                
            else:
                dfs(node.left , target-node.val , path)
                dfs(node.right , target-node.val , path)
            
            path.pop()
        
        dfs(root , targetSum , [])

        return ans
