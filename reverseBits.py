# Reverse bits of a given 32 bits unsigned integer.
# Note that in some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type.
# They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
# In Java, the compiler represents the signed integers using 2's complement notation.
# Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents the signed integer -1073741825.

class Solution:
    def reverseBits(self, n):
        res = 0
        for i in range(32):
            bit = (n >> i) & 1
            res = res | (bit << (31 - i))
        return res
      
# Explanation
# Res variable to store the bits
# Loop 32 times (32 bits)
# In each iteration of the loop, we shift right i times and perform a bitwise AND operation (if both bits are 1, it returns 1, otherwise it returns 0)
# Then, we left shift the extracted bit by negating 31, and performing a bitwise OR operation between the current value of res and the left-shift bit (if both bits are 0,
# the result is 0, otherwise it is 1)
# We start from the far right, use bitwise & to isolate the bit, then we shift the value of bit to the left since we are reversing, and finally use bitwise OR operation to
# combine the current result of res + the current bit
# Return RES
