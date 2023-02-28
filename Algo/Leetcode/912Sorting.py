class Solution(object):
    def sortArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        self.sort(nums, 0, len(nums)-1)

        return nums

    def sort(self, nums, l, r):
        if l < r:
            pivot = self.partition(nums, l, r)
            self.sort(nums, l, pivot-1)
            self.sort(nums, pivot+1, r)

    def partition(self, nums, l, r):
        pivot = self.random_idx(l, r)
        self.swap(nums, pivot, r)

        pivot = l
        for i in range(l, r):
            if nums[i] < nums[r]:
                self.swap(nums, i, pivot)
                pivot += 1

        self.swap(nums, pivot, r)

        return pivot

    def random_idx(self, l, r):
        return random.randint(l, r)

    def swap(self, nums, i, j):
        tmp = nums[i]
        nums[i] = nums[j]
        nums[j] = tmp


# This do not pass the case of 2222.....2222, need two pointer