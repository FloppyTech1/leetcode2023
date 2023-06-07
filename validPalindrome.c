// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters,
// it reads the same forward and backward. Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.


bool isPalindrome(char* s) {
    int len1 = strlen(s);
    int a, b, c, d;
    char* result = (char*)malloc((len1 + 1) * sizeof(char));

    for (int i = 0; s[i] != '\0'; i++) {
        result[i] = tolower(s[i]);
    }

    for (a = 0, b = 0; a < len1; a++) {
        if (isalnum(result[a])) {
            result[b++] = result[a];
        }
    }

    result[b] = '\0';

    int len2 = strlen(result);
    char* backUp = (char*)malloc((len2 + 1) * sizeof(char));
    strcpy(backUp, result);

    for (c = 0, d = len2 - 1; c < d; c++, d--) {
        char temp = backUp[c];
        backUp[c] = backUp[d];
        backUp[d] = temp;
    }
    
    bool isPalin = strcmp(result, backUp) == 0;

    return isPalin;
}

// Explanation
// Get the length of the initial string
// Initialize 4 variables for loops later on
// Allocate memory for a string Result of the same length as the initial string
// Convert the initial string to lowercase and store it into the new string Result
// Remove all spaces and punctuation by using isalnum (checks if a character is an alphabet) 
// Then the string is null-terminated at the final index to ensure it ends correctly 
// Get the length of our new string which has been converted to lowercase and removed of all space and punctuation
// Allocate memory for a backup string of the same size of our new string Result
// Create a copy using strcpy
// Create a reverse string of Result by taking the first character of the string, moving it to the end, and moving the end to the front by using a temporary char
// Check if the modified string and the reverse are identical by using strcmp
// Return result
