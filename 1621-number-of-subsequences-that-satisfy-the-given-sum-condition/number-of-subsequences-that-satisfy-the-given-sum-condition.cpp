class Solution {
public:
    int numSubseq(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;
        int mod = 1e9 + 7;
        int count = 0;

        // ✅ Allocate enough size: nums.size(), not nums.size() - 1
        std::vector<int> pow(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            pow[i] = (pow[i - 1] * 2) % mod;
        }

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                count = (count + pow[right - left]) % mod;
                left++;
            } else {
                right--;
            }
        }

        return count;
    }
};