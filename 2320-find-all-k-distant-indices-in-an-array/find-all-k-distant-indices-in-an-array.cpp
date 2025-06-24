
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> keyIndices;
        vector<int> result;

        // Step 1: Collect all indices where nums[j] == key
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == key) {
                keyIndices.push_back(j);
            }
        }

        // Step 2: Find all k-distant indices
        for (int i = 0; i < nums.size(); i++) {
            for (int j : keyIndices) {
                if (abs(i - j) <= k) {
                    result.push_back(i);
                    break; // Avoid duplicates
                }
            }
        }

        // Step 3: Sort result (optional, as indices are naturally ordered)
        sort(result.begin(), result.end());
        return result;
    }
};