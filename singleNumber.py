# Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
# You must implement a solution with a linear runtime complexity and use only constant extra space.

class Solution(object):
    def singleNumber(self, nums):
        xor = 0
        for num in nums:
            xor = num ^ xor
        return xor
      
# Explanation
# Since every element appears twice except for one element, we can use XOR
# In general, the XOR operator compares the binary representation of two numbers bit by bit and returns a result based on the following rule:
# If the corresponding bits are different, the XOR operator returns 1.
# If the corresponding bits are the same, the XOR operator returns 0.
# Example 5 XOR 7
# 5 in binary: 101
# 7 in binary: 111
# 1 and 1 returns 0, 0 and 1 returns 1, 1 and 1 returns 0
# Result: 010 = 2
# This means that the same binary numbers will always cancel out, and the only number remaining will be the single numer
# ^ is the XOR operator
