## python version. O(1) space. Recursive.
class Solution:
    def findValInList(self, list, start, end, target):
            if len(list)==0 or start > end:
                return None;
            idx = start;
            while idx <= end:
                if list[idx] == target:
                    return idx;
            return None;

    def reConstruct(self, pre, pre_start, pre_end, tin, tin_start, tin_end):
        root_val = pre[pre_start]

        root = TreeNode(root_val);
        idx = self.findValInList(tin, tin_start, tin_end, root_val)
        if idx is None:
            return None
        left_length = idx - tin_start
        right_lenth = tin_end - idx

        if left_length != 0:
            root.left = self.reConstruct(pre, pre_start+1, pre_start+left_length, tin, tin_start, idx-1)
        if right_length != 0:
            root.right = self.reConstruct(pre, pre_start+left_lenght+1, pre_end, tin, idx+1, tin_end)
        return root

    def reConstructBinaryTree(self, pre, tin):
        if len(pre) == 0 or len(tin == 0) or len(pre) != len(tin):
            return None
        root = self.reConstruct(pre, 0, len(pre)-1, tin, 0, len(tin)-1 )
        return root
