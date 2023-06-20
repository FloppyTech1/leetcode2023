# You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
# You can either start from the step with index 0, or the step with index 1.
# Return the minimum cost to reach the top of the floor (top floor is one floor after the last index of the array (out of bounds)).

class Solution(object):
    def minCostClimbingStairs(self, cost):
        cost.append(0)

        for i in range(len(cost) - 3, -1, -1):
            cost[i] = min(cost[i] + cost[i+1], cost[i] + cost[i+2])

        return min(cost[0], cost[1])
   
# Explanation
# Append 0 to the list that way we have an ending to aim for
# Loop going downwards, starting at the 3 element from the end, because the last element is the end, the second last element doesn't need to be modified since it can only 
# move 1 step and not two steps
# Recalculate the cost at each index to be the minimum of either taking 1 step or two steps to reach the end
# The value at each index is the value it takes to read the end, example [10, 15, 20, 0],  (0 is added for an end target) from 20 it takes 1 step to reach the end, so it costs
# 20 from 20 to reach the end. From 15, it can either cost 15 + 20 if we take 1 step, or 15 + 0 if we take two steps, the min is 15 so 15 stays as the value in the list.
# From 10 it can either be 10 + 15 which is 25 or 10 + 20 which is 30, so we update it to 25. Now we have [25, 15, 20, 0] and we return the min of 25, 15 which is 15.
