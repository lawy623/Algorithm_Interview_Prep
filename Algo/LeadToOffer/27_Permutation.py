## the order is shit.
class Solution:
    def Permutation(self, ss):
        if len(ss)==0:
            return []
        if len(ss)==1:
            return ss

        res = [ss[0]]
        for i in range(1,len(ss)):
            new_val = ss[i]
            leng = len(res)
            for j in range(leng):
                pre = res[j]
                for k in range(len(pre), -1, -1):
                    new_s = pre[:k] + new_val + pre[k:]
                    res.append(new_s)

            res = res[leng:]

        res_dict = {}
        res_ = []
        for x in res:
            if x not in res_dict:
                res_dict[x] = 1
                res_.append(x)
        res_.sort()

        return res_


# recursion
class Solution(object):

    def __init__(self):
        self.res = []
        self.path = []

    def permutation(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        s = sorted(s)  # avoid repeat
        self.n = len(s)
        self.dfs(s)

        return list(set(self.res))

    def dfs(self, s):
        if len(self.path) == self.n:
            self.res.append(''.join(self.path))
            return

        for i, n in enumerate(s):
            tmp = s[:i] + s[i + 1:]
            self.path.append(n)
            self.dfs(tmp)
            self.path.pop()