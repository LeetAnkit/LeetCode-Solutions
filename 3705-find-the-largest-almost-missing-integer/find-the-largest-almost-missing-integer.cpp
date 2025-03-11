class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        int n = nums.size();
        
        // Iterate through the array and count the number of subarrays in which each integer appears
        for (int i = 0; i <= n - k; ++i) {
            unordered_map<int, bool> seen;
            for (int j = i; j < i + k; ++j) {
                if (!seen[nums[j]]) {
                    countMap[nums[j]]++;
                    seen[nums[j]] = true;
                }
            }
        }
        
        // Find the largest integer that appears in exactly one subarray of size k
        int result = -1;
        for (const auto& pair : countMap) {
            if (pair.second == 1) {
                result = max(result, pair.first);
            }
        }
        
        return result;
        
    }
};