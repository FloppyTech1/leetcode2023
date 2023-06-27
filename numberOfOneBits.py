# Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
# Note: Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type.
# It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
# In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3, the input represents the signed integer. -3.

class Solution(object):
    def hammingWeight(self, n):
        binaryString = bin(n)
        length = len(binaryString)
        counter = 0
        for i in range(0, length):
            if binaryString[i] == '1':
                counter = counter + 1
        
        return counter
     
# Explanation
# Create a string with the integer n being converted to binary
# Get the length of the string
# Set a counter
# Loop over the string and increment counter at each encounter of '1'
# Return counter
