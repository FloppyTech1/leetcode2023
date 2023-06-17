# Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.
# Implement KthLargest class:
# KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
# int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.

class KthLargest(object):

    def __init__(self, k, nums):
        self.minHeap = nums
        self.k = k
        heapq.heapify(self.minHeap)
        while len(self.minHeap) > k:
            heapq.heappop(self.minHeap)

    def add(self, val):
        heapq.heappush(self.minHeap, val)
        if len(self.minHeap) > self.k:
            heapq.heappop(self.minHeap)
        return self.minHeap[0]
  
# Explanation
# Constructor
# Assign the nums array to a variable minHeap (so we can use it in the class, that's why we use self)
# Assign the value of k to an instance variable to keep track of k (so we can use it in the class, that's why we use self)
# Use heapq.heapify to create a heap structure from the original nums array
# While the length of our heap is greater than k, pop from the heap that way our window of integers is only of k size
# By keeping our window to only k size, the smallest element of this window size will be the first index of our window
# Add
# Push the value onto the heap
# If the length of the heap is larger than k, pop from the heap
# This way we keep our window size to only k
# Return the minimum value
