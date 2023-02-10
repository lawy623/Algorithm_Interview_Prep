# Use dict
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        m = {}
        for n in nums:
            if m.get(n) is not None:
                m[n] += 1
            else:
                m[n] = 1

        res = []
        for k, v in m.items():
            if v > len(nums) / 3:
                res.append(k)

        return res

# Use moore
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        count1, count2 = 0, 0
        elem1, elem2 = None, None
        # Make sure that each elem is identical
        for n in nums:
            if (n == elem1):
                count1 += 1
            elif (n == elem2):
                count2 += 1
            elif count1 == 0:
                count1 += 1
                elem1 = n
            elif count2 == 0:
                count2 += 1
                elem2 = n
            else:
                count1 -= 1
                count2 -= 1

        # recount the num
        count1, count2 = 0, 0
        for n in nums:
            if n == elem1:
                count1 += 1
            if n == elem2:
                count2 += 1

        # count super num
        res = []
        if count1 > len(nums) / 3:
            res.append(elem1)
        if count2 > len(nums) / 3:
            res.append(elem2)

        return res