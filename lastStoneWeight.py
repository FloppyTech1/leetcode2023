# You are given an array of integers stones where stones[i] is the weight of the ith stone.
# We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. 
# Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:
# If x == y, both stones are destroyed, and
# If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
# At the end of the game, there is at most one stone left.
# Return the weight of the last remaining stone. If there are no stones left, return 0.

class Solution(object):
    def lastStoneWeight(self, stones):
        stones = [-s for s in stones]
        heapq.heapify(stones)

        while len(stones) > 1:
            heaviest = heapq.heappop(stones)
            secondHeaviest = heapq.heappop(stones)
            if secondHeaviest == heaviest:
                continue
            elif secondHeaviest != heaviest:
                newStone = heaviest - secondHeaviest
                heapq.heappush(stones, newStone)
        
        if len(stones) == 1:
            return -stones[0]
        else:
            return 0
# Explanation
# Create a maxHeap from stones by negating all stones in stones
# While the length of stones is greater than 1 do the following: (since we only want the last stone, or 0 stones)
# Pop the heaviest and second heaviest stones and assign them to variables (According to the rules given, these stones will always be popped)
# If the stones are equal, continue as they have already been popped
# If the secondHeaviest is less than the heaviest, create a new stone and push it to the heap
# Check if the length of stones is 1, if so return the last stone (negate it so it returns positive)
# Otherwise return 0
