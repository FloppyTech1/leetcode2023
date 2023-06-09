// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

int maxProfit(int* prices, int pricesSize){
    int max = 0;
    int result = 0;
    int min = prices[0];
    for(int i = 0; i < pricesSize; i++){
        if (prices[i] < min){
            min = prices[i];
        }
        else{
            result = prices[i] - min;
            if (result > max){
                max = result;
            }
        }
    }
    return max;
}

// Initialize a max, result and min variable
// Loop over the array
// If the current price is less than the minimum, update min
// Otherwise, calculate the result and check if it is greater than the current max
// Return max
