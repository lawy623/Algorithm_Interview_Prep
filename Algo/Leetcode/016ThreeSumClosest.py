class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums = sorted(nums)
        n = len(nums)
        res = []
        clost_sum = 0
        dis = sys.maxint
        for i in range(0, n-2):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            j = i+1
            k = n-1
            while j < k:
                if k < n-1 and nums[k] == nums[k+1]:
                    k -= 1
                elif j > i+1 and nums[j] == nums[j-1]:
                    j += 1
                else:
                    if nums[i] + nums[j] + nums[k] == target:
                        return target
                    elif nums[i] + nums[j] + nums[k] > target:
                        if abs(nums[i] + nums[j] + nums[k] - target) < dis:
                            clost_sum = nums[i] + nums[j] + nums[k]
                            dis = abs(nums[i] + nums[j] + nums[k] - target)
                        k -= 1
                    else:
                        if abs(nums[i] + nums[j] + nums[k] - target) < dis:
                            clost_sum = nums[i] + nums[j] + nums[k]
                            dis = abs(nums[i] + nums[j] + nums[k] - target)
                        j += 1

        return clost_sum