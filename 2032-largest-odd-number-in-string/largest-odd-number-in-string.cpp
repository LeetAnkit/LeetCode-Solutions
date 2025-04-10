class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();

        // Find the last odd digit in the string
        for (int i = n - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 != 0) {
                return num.substr(0, i + 1); // Return substring up to that point
            }
        }

        return ""; // No odd-numbered substring found
    }
};
