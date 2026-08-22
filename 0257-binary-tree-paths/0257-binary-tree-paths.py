class Solution(object):
    def binaryTreePaths(self, root):
        result = []

        def dfs(node, path):
            if node is None:
                return

            path.append(str(node.val))

            if node.left is None and node.right is None:
                result.append("->".join(path))
            else:
                dfs(node.left, path)
                dfs(node.right, path)

            path.pop()

        dfs(root, [])

        return result