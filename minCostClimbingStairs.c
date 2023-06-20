// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
// You can either start from the step with index 0, or the step with index 1.
// Return the minimum cost to reach the top of the floor.

int minCostClimbingStairs(int* cost, int costSize){
    cost = realloc(cost, (costSize + 1) * sizeof(int));
    cost[costSize] = 0;
    int first = 0;
    int second = 0;

    for(int i = costSize - 3; i >= 0; i--){
        first = cost[i] + cost[i+1];
        second = cost[i] + cost[i+2];
        if (first > second){
            cost[i] = second;
        }
        else{
            cost[i] = first;
        }
    }

    if (cost[0] > cost[1]){
        return cost[1];
    }
    return cost[0];
}

// Explanation
// Reallocate memory size of the array to append one more element (target element 0)
// Initialize two variables to store results
// Read python for explanation (same explanation), just no min() function
