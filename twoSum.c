// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *returnArray = malloc(2 * sizeof(int));
    returnArray[0] = 0;
    returnArray[1] = 1;

    for(int i = 0; i < numsSize; i++){
        for(int j = 0; j < numsSize; j++){
            if(j != i){
                if(nums[i] + nums[j] == target){
                    returnArray[0] = i;
                    returnArray[1] = j;
                    *returnSize = 2;
                    return returnArray;
                }
            }
        }
    }
    *returnSize = 2;
    return returnArray;
}

// Explanation
// Allocate memory for an array of size 2 and assign the indexes temporary values
// Nested loop to iterate over all combinations
// If statement to ensure that we are not adding an index to itself
// If a combination is found, assign indexes to the returnArray
// Assign returnSize to 2
// Return returnArray
