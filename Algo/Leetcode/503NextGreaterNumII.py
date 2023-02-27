class Solution(object):
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        _nums = nums + nums[:-1]
        n = len(nums)
        res = [-1] * n

        st = []
        for i, k in enumerate(_nums):
            while len(st) > 0 and st[-1][1] < k:
                top = st.pop()
                res[top[0] % n] = k
            st.append((i, k))

        return res