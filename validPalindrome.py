# Given a string s, return true if it is a palindrome, or false otherwise.

import re

class Solution(object):
    def isPalindrome(self, s):
        s = re.sub(r'[^\w\s]', '', s)
        s = s.replace(" ", "")
        s = s.replace("_", "")
        s_lower = s.lower()
        reversed_s = s[::-1]
        reversed_s = reversed_s.replace(" ", "")
        reversed_lower = reversed_s.lower()

        if s_lower == reversed_lower:
            return True
        else:
            return False
  
# Explanation
# Remove all spaces and punctuation characters from the string
# Convert the string to lowercase
# Create a new string reversed which is the reverse of the original string s
# Remove all spaces from the reversed string
# Convert the reversed string to lowercase
# Check if both strings are equal, return true if true, otherwise return false
