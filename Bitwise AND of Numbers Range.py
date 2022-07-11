Bitwise AND of Numbers Range: -


The solution in Python: -


import math
class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        ans = 0
        if left == 0 or right == 0: return 0
        while left and right:
            left_most_sbit = int(math.log2(left))
            right_most_sbit = int(math.log2(right))
            if left_most_sbit==right_most_sbit:
                ans = ans | 1<<left_most_sbit
                left = left - (1<<left_most_sbit)
            else:
                break
            right = right - (1<<right_most_sbit)
        return ans




