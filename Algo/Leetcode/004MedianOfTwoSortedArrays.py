# only brute force
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        n1 = len(nums1)
        n2 = len(nums2)
        if n1 + n2 == 0:
            return 0.0

        i, j = 0, 0
        mid = (n1 + n2 - 1) / 2
        rem = (n1 + n2) % 2 == 1
        while i + j < mid:
            if i < n1 and j < n2:
                if nums1[i] <= nums2[j]:
                    i += 1
                else:
                    j += 1
            elif i == n1:
                j += 1
            else:
                i += 1

        if i == n1:
            return nums2[j] if rem else (nums2[j] + nums2[j+1]) / 2.0
        elif j == n2:
            return nums1[i] if rem else (nums1[i] + nums1[i+1]) / 2.0
        else:
            if rem:
                return min(nums1[i], nums2[j])
            else:
                if nums1[i] < nums2[j]:
                    if i == n1 - 1:
                        return (nums1[i] + nums2[j]) / 2.0
                    else:
                        return (nums1[i] + min(nums1[i+1], nums2[j])) / 2.0
                else:
                    if j == n2 - 1:
                        return (nums1[i] + nums2[j]) / 2.0
                    else:
                        return (nums2[j] + min(nums2[j+1], nums1[i])) / 2.0
