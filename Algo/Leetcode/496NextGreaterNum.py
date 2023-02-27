class Solution(object):
    def nextGreaterElement(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """

        d = {}
        for n in nums2:
            d[n] = -1

        st = []
        for n in nums2:
            while len(st) > 0 and st[-1] < n:       # all the top on stack meet next larger n
                t = st.pop()
                d[t] = n
            st.append(n)

        res = []
        for n in nums1:
            res.append(d[n])

        return res