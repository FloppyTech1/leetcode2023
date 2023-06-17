// Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.
// Implement KthLargest class:
// KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
// int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.

typedef struct {
    int k;
    int heap[];
} KthLargest;

int cmp(const void *const restrict a, const void *const restrict b)
{
    return *(int *)a - *(int *)b;
}

KthLargest *kthLargestCreate(const int k, int *const nums, const int n)
{
    qsort(nums, n, sizeof(int), cmp);
    KthLargest *const ret = malloc(sizeof(KthLargest) + k * sizeof(int));
    ret->k = k;

    const int filler = n < k ? k - n : 0;
    memcpy(ret->heap + filler, filler ? nums : nums + n - k, (filler ? n : k) * sizeof(int));
    for (int i = 0; i < filler; ++i)
        ret->heap[i] = INT_MIN;

    return ret;
}

int kthLargestAdd(KthLargest *const obj, const int val)
{
    if (val <= obj->heap[0])
        return obj->heap[0];

    obj->heap[0] = val;
    for (int i = 0; 2 * i + 1 < obj->k;) {
        const int l = 2 * i + 1, r = l + 1;
        if (obj->heap[l] >= obj->heap[i] && (r >= obj->k || obj->heap[r] >= obj->heap[i]))
            break;

        const int next = r >= obj->k || obj->heap[l] < obj->heap[r] ? l : r;
        const int tmp = obj->heap[i];
        obj->heap[i] = obj->heap[next];
        obj->heap[next] = tmp;
        i = next;
    }

    return obj->heap[0];
}

void kthLargestFree(KthLargest *const obj)
{
    free(obj);
}

// Explanation
// Initialize a struct with k and a heap
// Create a helper function (for qsort) cmp to help sort the array
// Constructor
// Use qsort to sort the array
// Allocate memory for the kthLargest structure (size of structure + k since the heap is a flexible array)
// K value is assigned to the k member of the structure
// Initialize filler variable to check if the heap needs to be filled (only if the size of the heap is less than k)
// Use memcpy to copy elements from nums array into the heap array
// If filler is non-zero, it means some elements need to be filled, so 'filler' elements are copied from nums array starting from the beginning
// Otherwise only k elements are copied
// For loop to assign any filler elements by using INT_MIN
// Return the heap
// Add
// If the value trying to be added is less than the current smallest element, return the current smallest element
// If it is greater, the new value replaces the smallest value in it's position
// For loop to maintain the heap structure/properties
// Return the smallest element
// Destructor
// Free the allocated memory
