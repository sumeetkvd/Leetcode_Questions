Candy: -


The solution in Python: -


from itertools import *
  
class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        dp = [1] * n
        
        for i in range(1, n):
            if ratings[i] > ratings[i - 1] and dp[i] <= dp[i - 1]:
                dp[i] = dp[i - 1] + 1

        for i in range(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1] and dp[i] <= dp[i + 1]:
                dp[i] = dp[i + 1] + 1

        return sum(dp)


