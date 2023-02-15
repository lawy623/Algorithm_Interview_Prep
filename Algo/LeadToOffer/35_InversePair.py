class Solution(object):
    def reversePairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if len(nums) == 0:
            return 0
        return mergeCount(nums, 0, n - 1)

def swap(nums, l, r):
    tmp = nums[l]
    nums[l] = nums[r]
    nums[r] = tmp

def mergeCount(nums, l, r):
    if l == r:
        return 0
    if l == r - 1:
        if nums[l] > nums[r]:  # remember to move it here!!!
            swap(nums, l, r)
            return 1
        else:
            return 0

    m = (l + r) / 2
    c = mergeCount(nums, l, m) + mergeCount(nums, m + 1, r)
    tmp = []
    i, j = l, m + 1
    while (i <= m or j <= r):
        if i <= m and j <= r:
            if nums[i] > nums[j]:
                c += m - i + 1
                tmp.append(nums[j])
                j += 1
            else:
                tmp.append(nums[i])
                i += 1
        elif i <= m:
            tmp.append(nums[i])
            i += 1
        elif j <= r:
            tmp.append(nums[j])
            j += 1

    assert (len(tmp) == r - l + 1)
    nums[l:r + 1] = tmp

    return c
