class TopEndNode:
    def __init__(self):
        self.top = None
        self.end = None

class Solution:
    def Convert(self, pRootOfTree):
        if pRootOfTree is None:
            return None

        res = self.ConvertNode(pRootOfTree)
        return res.top

    def ConvertNode(self, pRootOfTree):
        res = TopEndNode()
        if pRootOfTree is None:
            return res

        list_left = self.ConvertNode(pRootOfTree.left)
        list_right = self.ConvertNode(pRootOfTree.right)

        if list_left.end is not None:
            list_left.end.right = pRootOfTree
            pRootOfTree.left = list_left.end
        else:
            list_left.top = pRootOfTree

        if list_right.top is not None:
            list_right.top.left = pRootOfTree
            pRootOfTree.right = list_right.top
        else:
            list_right.end = pRootOfTree

        res.top = list_left.top
        res.end = list_right.end

        return res
