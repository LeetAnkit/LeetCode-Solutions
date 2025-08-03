class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> targetFreq;
    for (char c : t) targetFreq[c]++;

    int count = 0, left = 0, minLen = INT_MAX, start = 0;

    for (int right = 0; right < s.size(); ++right) {
        char c = s[right];
        targetFreq[c]--;

        if (targetFreq[c] >= 0) count++;

        while (count == t.size()) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            char leftChar = s[left];
            targetFreq[leftChar]++;
            if (targetFreq[leftChar] > 0) count--;
            left++;
        }
    }

    return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};