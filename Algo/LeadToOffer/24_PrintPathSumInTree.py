## recursively find down.
class Solution:
    def FindPath(self, root, expectNumber):
        paths = []
        if root is None:
            return []

        if root.left is None and root.right is None and root.val==expectNumber:
            paths.append([expectNumber])

        if root.left is not None:
            temp = self.FindPath(root.left, expectNumber - root.val)
            if len(temp)!=0 and len(temp[0])!=0:
                for v in temp:
                    v = [root.val] + v
                    paths.append(v)
        if root.right is not None:
            temp = self.FindPath(root.right, expectNumber - root.val)
            if len(temp)!=0 and len(temp[0])!=0:
                for v in temp:
                    v = [root.val] + v
                    paths.append(v)
        return paths
