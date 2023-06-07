// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

bool isAnagram(char *s, char *t) {
    if (strlen(s) != strlen(t)) {
        return false;
    }

    int len1 = strlen(s);
    int len2 = strlen(t);

    int letterCount1[26] = {0};
    int letterCount2[26] = {0};    

    for(int i = 0; i < len1; i++)
    {
        int lower = tolower(s[i]);
        letterCount1[lower - 'a']++;
    }

    for(int i = 0; i < len2; i++)
    {
        int lower = tolower(t[i]);
        letterCount2[lower - 'a']++;
    }

    for(int i = 0; i < 26; i++)
    {
        if (letterCount1[i] != letterCount2[i])
        {
            return false;
        }
    }

    return true;
}

// Explanation
// Check if strings are of equal length, otherwise return false
// Obtain length of both strings
// Initialize two arrays for each string with 26 indexes (for each letter in the alphabet) each starting at 0
// Loop over the length of the first string, convert the letter to lowercase, subtract it from 'a' so we get the apropriate index, and add 1 to the appropriate index
// Do the same for the second string
// Loop over the entirety of both arrays, if each index is equal return true, otherwise return false
