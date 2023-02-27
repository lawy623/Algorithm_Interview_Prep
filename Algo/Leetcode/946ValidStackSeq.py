class Solution(object):
    def validateStackSequences(self, pushed, popped):
        """
        :type pushed: List[int]
        :type popped: List[int]
        :rtype: bool
        """
        stack = []
        n = len(pushed)
        i = 0
        j = 0
        while i < n+1 and j < n:
            if len(stack) > 0 and stack[-1] == popped[j]:
                stack.pop()
                j += 1
            elif i < n:
                stack.append(pushed[i])
                i += 1
            else:
                break

        return j == n