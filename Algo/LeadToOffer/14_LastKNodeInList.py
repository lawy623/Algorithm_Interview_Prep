## python. two pointer. O(n) time.
class Solution:
    def FindKthToTail(self, head, k):
        if k <= 0:
            return None

        first = head
        while k>0:
            if first is None:
                return None
            first = first.next
            k -= 1

        second = head
        while first is not None:
            first = first.next
            second = second.next
        return second
