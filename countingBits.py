# Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

class Solution(object):
    def countBits(self, n):
        ans = []
        for i in range(0, n+1):
            counter = 0
            binaryString = bin(i)
            for j in range(0, len(binaryString)):
                if binaryString[j] == '1':
                    counter = counter+1
            ans.append(counter)
        
        return(ans)

# Explanation
# Create the ans array
# Loop n+1 times
# Set counter and also reset it every time we move onto the next n
# Create the binaryString of n
# Loop over the string 
# If index is 1, increase counter
# Append counter to the ans array
# Return ans
