# You are climbing a staircase. It takes n steps to reach the top.
# Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

class Solution(object):
    def climbStairs(self, n):
        one = 1
        two = 1

        for i in range(n - 1):
            temp = one
            one = one + two
            two = temp
        
        return one
    
# Explanation
# Initialize two variables, one and two to be equal to 1 (the last two numbers, for example if n = 50, from 49 and 50, there's two distinct way to reach 50 (1, 1)
# Loop n - 1 times (Since we have already initiailized two variables, if n = 5, we already know 5 and 4, so we only need to know 0 1 2 3 which is 4, n(5) - 1 = 4.
# Create a temporary variable to store one
# Increase one by the value of two (bottom-up approach)
# Assign two to the old value of one (bottom-up approach)
# Return one
