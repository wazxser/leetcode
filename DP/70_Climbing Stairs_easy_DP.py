class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [0 for i in xrange(n+1)]
        
        dp[1] = 1
        if n > 1:
            dp[2] = 2
            for i in xrange(3, n+1):
                dp[i] = dp[i-1] + dp[i-2]
            
        return dp[n]