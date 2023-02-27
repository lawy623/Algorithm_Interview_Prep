class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        n = len(s)
        i = 0
        st = []
        while i < n:
            if s[i] == ')' and len(st) > 0 and st[-1] == '(':
                st.pop()
            elif s[i] == '}' and len(st) > 0 and st[-1] == '{':
                st.pop()
            elif s[i] == ']' and len(st) > 0 and st[-1] == '[':
                st.pop()

            else:
                st.append(s[i])

            i += 1

        return len(st) == 0