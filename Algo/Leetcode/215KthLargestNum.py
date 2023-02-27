class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        l, r = 0, n-1
        pivot = self.partition(nums, l, r)
        while pivot != k-1:
            if pivot < k-1:
                l = pivot + 1
            else:
                r = pivot - 1
            pivot = self.partition(nums, l, r)

        return nums[pivot]

    def partition(self, nums, l, r):
        if l >= r:
            return l

        target = nums[r]
        pivot = l
        for i in range(l, r):
            if nums[i] >= target:
                self.swap(nums, i, pivot)
                pivot += 1

        self.swap(nums, r, pivot)

        return pivot

    def swap(self, nums, i, j):
        tmp = nums[i]
        nums[i] = nums[j]
        nums[j] = tmp