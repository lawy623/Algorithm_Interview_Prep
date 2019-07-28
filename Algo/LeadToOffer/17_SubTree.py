class Solution:
    def HasSubtree(self, pRoot1, pRoot2):
        res = False

        if pRoot1 is None or pRoot2 is None:
            return False

        if pRoot1.val == pRoot2.val:
            res = self.SameTree(pRoot1, pRoot2)
        if not res:
            res = self.HasSubtree(pRoot1.left, pRoot2)
        if not res:
            res = self.HasSubtree(pRoot1.right, pRoot2)

        return res

    def SameTree(self, pRoot1, pRoot2):
        if pRoot2 is None:
            return True
        if pRoot1 is None:
            return False
        if pRoot1.val != pRoot2.val:
            return False

        return self.SameTree(pRoot1.left, pRoot2.left) and self.SameTree(pRoot1.right, pRoot2.right)
