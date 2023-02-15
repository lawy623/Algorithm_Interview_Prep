class Solution:
    def GetNumberOfK(self , data: List[int], k: int) -> int:
        # write code here
        return binary_count(data, k, 0, len(data)-1)


def binary_count(data, k, l, r):
    if l > r:
        return 0
    if l == r:
        return 1 if data[l] == k else 0

    m = int((l + r) / 2)
    if data[m] == k:
        return binary_count(data, k, l, m-1) + binary_count(data, k, m+1, r) + 1
    elif data[m] > k:
        return binary_count(data, k, l, m-1)
    else:
        return binary_count(data, k, m+1, r)