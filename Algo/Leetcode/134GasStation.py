class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        n = len(gas)
        val = 0
        start = 0
        res = 0     # keep all the difference sum. If sum(diff) > 0, can find a way
        for i in range(n):
            val += (gas[i] - cost[i])
            res += (gas[i] - cost[i])
            # start can not be i
            if (val < 0):
                start = i+1
                val = 0

        return -1 if res < 0 else start