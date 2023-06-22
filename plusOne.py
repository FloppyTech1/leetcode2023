# You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer.
# The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
# Increment the large integer by one and return the resulting array of digits.

class Solution(object):
    def plusOne(self, digits):
        stringNum = ""
        for i in range(0, len(digits)):
            stringNum += str(digits[i])
        
        result = int(stringNum) + 1
        digitsResult = [int(i) for i in str(result)]
        return digitsResult
     
# Explanation
# Create an empty string
# Add the list of numbers to the string (now we have a string with "123")
# Create a variable result, store the integer value of the string and increment it by 1 (now we have an int result = 124)
# Create a new result array and store the digit values from result (now we have an array [1, 2, 4[)
# Return digitsResult
