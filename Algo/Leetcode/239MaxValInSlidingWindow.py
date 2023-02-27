class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        q = []
        res = []
        for i in range(len(nums)):
            while len(q) > 0 and q[0] <= i-k:    # too old
                q.pop(0)
            while len(q) > 0 and nums[q[-1]] < nums[i]:   # most cur but small ones
                q.pop()
            q.append(i)
            if i >= k-1:
                res.append(nums[q[0]])

        return res
