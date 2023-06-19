// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

int climbStairs(int n){
    int one = 1;
    int two = 1;
    int temp = 0;

    for (int i = 0; i < n - 1; i++){
        temp = one;
        one = one + two;
        two = temp;
    }

    return one;
}

// Explanation
// Initialize three variables, one, two and temp
// Loop n-1 times
// Assign temp to one, increment one by two and assign temp to two
// Return one
