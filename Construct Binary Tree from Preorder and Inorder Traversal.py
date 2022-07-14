Construct Binary Tree from Preorder and Inorder Traversal: -


The solution in Python: -


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
  
        if not preorder:
            return None
        
        ind = {inorder[i]:i for i in range(len(inorder))}
        
        def build(low,high):
            if low>high:
                return None
            val = next(nextnode)
            root = TreeNode(val)
            root.left = build(low,ind[val]-1)
            root.right = build(ind[val]+1,high)
            return root
        
        nextnode = iter(preorder)
        return build(0,len(inorder)-1)