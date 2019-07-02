import numpy as np

## quicksort. O(nlogn)-> bad O(n^2). Unstable.
def quicksort(nums):
    if len(nums) == 0:
        return
    quicksort_range(nums, 0, len(nums))

def quicksort_range(nums, start, end):
    if start<end-1:
        q = partition(nums, start, end)
        quicksort_range(nums, start, q)
        quicksort_range(nums, q+1, end)

def partition(nums, start, end):
    pivot = nums[end-1]
    idx = start-1
    for i in range(start, end-1):
        if nums[i] <= pivot:
            idx += 1
            nums[i], nums[idx] = nums[idx], nums[i]
    nums[idx+1], nums[end-1] = nums[end-1], nums[idx+1]
    return idx+1


if __name__ == '__main__':
    x = np.random.randint(100, size=40)
    y = x.tolist()
    print("Before:", y)
    quicksort(y)
    print("After:", y)
