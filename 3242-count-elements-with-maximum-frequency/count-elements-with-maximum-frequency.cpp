class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0, sum = 0;

        // First pass build frequency map and track max frequency
        for (int num : nums) {
            int f =++freq[num];
            if (f > maxFreq) {
                maxFreq = f;
            }
        }

        // Second pass\ sum frequencies equal to maxFreq
        for ( auto& [num, f] : freq) {
            if (f == maxFreq) {
                sum += f;
            }
        }

        return sum;
    }
};