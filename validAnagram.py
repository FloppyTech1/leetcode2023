# Given two strings s and t, return true if t is an anagram of s, and false otherwise.

class Solution(object):
    def isAnagram(self, s, t):
        if len(s) != len(t):
            return False
        
        dict_s = {}
        dict_t = {}
        for char in s:
            if char in dict_s:
                dict_s[char]+=1
            else:
                dict_s[char]=1

        for char in t:
            if char in dict_t:
                dict_t[char]+=1
            else:
                dict_t[char]=1
        
        if dict_s == dict_t:
            return True

# Explanation
# If the length of both strings are different, they cannot be an anagram
# Initialize two different dictionaries
# For each char in the string s, if that char is already in dict_s, we increment it by one, otherwise we assign it the value of 1
# Repeat same steps for string t
# If both dictionaries are equivalent, return TRUE
