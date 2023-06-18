// You are given an array of integers stones where stones[i] is the weight of the ith stone.
// We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. 
// Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:
// If x == y, both stones are destroyed, and
// If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
// At the end of the game, there is at most one stone left.
// Return the weight of the last remaining stone. If there are no stones left, return 0.

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int lastStoneWeight(int* stones, int stonesSize){
    for (int i = 0; i < stonesSize; i++){
        stones[i] = -stones[i];
    }

    qsort(stones, stonesSize, sizeof(int), compare);
    while(stonesSize > 1){
        int heaviest = stones[0];
        int secondHeaviest = stones[1];

        if (secondHeaviest == heaviest){
            stones[0] = 0;
            stones[1] = 0;
        }
        else{
            stones[0] = heaviest - secondHeaviest;
            stones[1] = 0;
        }
        qsort(stones, stonesSize, sizeof(int), compare);
        stonesSize--;
    }
    return -stones[0];
}

// Explanation
// Compare function to assist qsort
// Loop over stones and negate them to create a maxHeap
// Sort the maxHeap
// Loop while size is greater than 1
// Initialize two variables to the heaviest and secondHeaviest
// If they are equal, set both to 0
// If they are not, reassign stones[0] to heaviest - secondHeaviest and set secondHeaviest to 0
// Resort the maxHeap and reduce the size
// Return the last element
