#include <iostream>
#include <string>
#include <cctype>

class Solution {
private:
    // Recursive helper function with start and end pointers
    bool isPalindromeRecursive(const std::string& s, int i, int j) {
        // Base Case: Pointers meet or cross. The string is a palindrome.
        if (i >= j) {
            return true;
        }

        // Skip non-alphanumeric characters from the left
        if (!std::isalnum(s[i])) {
            return isPalindromeRecursive(s, i + 1, j);
        }
        
        // Skip non-alphanumeric characters from the right
        if (!std::isalnum(s[j])) {
            return isPalindromeRecursive(s, i, j - 1);
        }

        // Compare characters (case-insensitively)
        if (std::tolower(s[i]) != std::tolower(s[j])) {
            return false;
        }

        // Recursive Step: Check the inner substring
        return isPalindromeRecursive(s, i + 1, j - 1);
    }

public:
    bool isPalindrome(std::string s) {
        if (s.empty()) {
            return true; // An empty string is considered a valid palindrome
        }
        return isPalindromeRecursive(s, 0, s.size() - 1);
    }
};
