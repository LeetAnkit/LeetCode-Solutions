#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = 0;
        int n = nums.size();

        // Step 1: Calculate total sum
        for (int num : nums) {
            totalSum += num;
        }

        // Step 2: Find remainder we need to remove
        int target = totalSum % p;
        if (target == 0) return 0;  // Already divisible

        // Step 3: Use prefix sums + hashmap to find shortest subarray
        unordered_map<int, int> prefixIndex;
        prefixIndex[0] = -1;  // Base case

        long long prefixSum = 0;
        int minLen = n;

        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            int currMod = prefixSum % p;

            // We want (currMod - target) % p seen before
            int need = (currMod - target + p) % p;

            if (prefixIndex.find(need) != prefixIndex.end()) {
                minLen = min(minLen, i - prefixIndex[need]);
            }

            // Store latest index of currMod
            prefixIndex[currMod] = i;
        }

        return (minLen == n ? -1 : minLen);
    }
};