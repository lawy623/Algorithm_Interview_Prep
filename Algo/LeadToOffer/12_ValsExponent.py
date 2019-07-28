## python version with O(logn) time.
class Solution:
    def Power(self, base, exponent):
        if base == 0:
            if exponent == 0: return 0
            elif exponent < 0: raise RuntimeError("Can not run")
            else: return 0
        else:
            if exponent == 0: return 1

            if exponent < 0:
                base = 1.0 / base
                exponent = -exponent

            return self.power_positive_exp(base, exponent)

    def power_positive_exp(self, base, exponent):
        assert(exponent > 0), "exponent should be positive"
        if exponent == 1: return base

        res = self.power_positive_exp(base, exponent >> 1)
        res *= res
        if exponent & 1:
            res *= base
        return res
