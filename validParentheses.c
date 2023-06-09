// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

bool isValid(char *s) {
    int size = strlen(s);
    char *myList = (char *)malloc((size + 1) * sizeof(char));
    int myListSize = 0;

    for (int i = 0; i < size; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            myList[myListSize] = s[i];
            myListSize++;
        }
        else if (s[i] == ')' && myListSize != 0 && myList[myListSize - 1] == '(') {
            myListSize--;
        }
        else if (s[i] == ']' && myListSize != 0 && myList[myListSize - 1] == '[') {
            myListSize--;
        }
        else if (s[i] == '}' && myListSize != 0 && myList[myListSize - 1] == '{') {
            myListSize--;
        }
        else {
            free(myList);
            return false;
        }
    }

    free(myList);

    if (myListSize == 0) {
        return true;
    }
    else {
        return false;
    }
}

// Explanation 
// Compute size of string
// Initialize an array (list) with size of string
// Initialize a variable for the list size
// Loop over string
// If current char is a open parantheses, append it to the list at the current list size and increase list size by 1
// If current char is a closed parantheses, the list is not empty, and the top of the list is the matching open parantheses, decrease list size
// Else return false
// Check if listSize is empty
// Return true or false
