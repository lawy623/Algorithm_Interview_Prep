class Solution(object):
    def nthSuperUglyNumber(self, n, primes):
        """
        :type n: int
        :type primes: List[int]
        :rtype: int
        """
        res = [1]
        n_p = len(primes)
        ptr = [0 for _ in range(n_p)]

        for i in range(n - 1):
            min_v = min([res[ptr[k]] * primes[k] for k in range(n_p)])
            res.append(min_v)
            for k in range(n_p):
                if min_v == res[ptr[k]] * primes[k]:
                    ptr[k] += 1

        return res[-1]