class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i, n in enumerate(nums):
            while nums[i] - 1 != i:         # consider the correspondence between nums[i] and i
                if nums[i] == nums[nums[i] - 1]:
                    return nums[i]

                swap(nums, i, nums[i] - 1)

        return -1

def swap(nums, i, j):
    tmp = nums[i]
    nums[i] = nums[j]
    nums[j] = tmp