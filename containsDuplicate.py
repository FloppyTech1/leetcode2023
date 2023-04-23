# Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

import array

class Solution(object):
    def containsDuplicate(self, nums):
        self.check = set()
        for number in nums:
            if number in self.check:
                return True
            else:
                self.check.add(number)
        return False
