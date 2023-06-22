# Write an algorithm to determine if a number n is happy.
# A happy number is a number defined by the following process:
# Starting with any positive integer, replace the number by the sum of the squares of its digits.
# Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
# Those numbers for which this process ends in 1 are happy.
# Return true if n is a happy number, and false if not.

class Solution(object):
    def isHappy(self, n):
        visit = set()
        while n not in visit:
            visit.add(n)
            n = self.sumOfSquares(n)
            if n == 1:
                return True
        return False
    
    def sumOfSquares(self, n):
        digits = [int(i) for i in str(n)]
        result = 0
        for i in range(0, len(digits)):
            result = result + digits[int(i)] ** 2
        
        return result
   
# Explanation
# Create a set to keep track of all numbers visited
# While n is not already visited
# Add n to the set
# Calculate the some of squares of n
# If n is == to 1, return true
# If we exit out of the while loop, return False
# sumOfSquares
# Create a list of digits by separating the integer into individual digits
# Loop over the length of the list of digits
# Increment result on each iteration by the digit ^ 2
# Return result
