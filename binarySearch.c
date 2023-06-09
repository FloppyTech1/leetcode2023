// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. 
// If target exists, then return its index. Otherwise, return -1.
// You must write an algorithm with O(log n) runtime complexity

int search(int* nums, int numsSize, int target){
    int start = 0;
    int end = numsSize - 1;
    int mid = 0;
    while(start <= end){
        mid = floor((start + end) / 2);
        if (nums[mid] == target){
            return mid;
        }
        else if (nums[mid] < target){
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return -1;
}

// Explanation
// Initialize a start, end and mid variable
// Loop while start is less than or equal to end
// Calculate the mid point
// If current mid is == target, return mid
// If current mid is less than target, reassign start to mid + 1
// Otherwise, reassign end to mid - 1
// Return -1
