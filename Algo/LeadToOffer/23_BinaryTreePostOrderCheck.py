class Solution(object):
    def verifyPostorder(self, postorder):
        """
        :type postorder: List[int]
        :rtype: bool
        """
        if len(postorder) <= 1:
            return True

        val = postorder[-1]
        i = 0
        n = len(postorder)

        # find split point
        while i < n and postorder[i] < val:
            i += 1

        # consider the second half all larger
        while i < n - 1:
            if postorder[i] < val:
                return False
            i += 1

        return self.verifyPostorder(postorder[:i]) and self.verifyPostorder(postorder[i:-1])