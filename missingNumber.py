# Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

class Solution(object):
    def missingNumber(self, nums):
        res = len(nums)

        for i in range(len(nums)):
            res += (i - nums[i])
        
        return res

# Explanation [0, 1, 2, 3, 5]
# Assign res the length of nums which will be 5 (res = 5)
# Loop over the nums array
# Increment result by i - nums[i] (0 - 0 = 0), (1 - 1 = 0), (2 - 2 = 0), (3 - 3 = 0) (4 - 5 = -1)
# 5 + - 1 = 4
# 4 is the missing number
# Return RES
