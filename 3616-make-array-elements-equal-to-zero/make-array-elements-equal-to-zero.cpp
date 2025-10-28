class Solution {
public:
    // Check if all elements are zero
    bool allZero(vector<int>& nums) {
        for (int ele : nums)
            if (ele != 0) return false;
        return true;
    }

    // Simulate the given process
    bool canMakeAllZero(vector<int> nums, int curr, int dir) {
        int n = nums.size();

        while (curr >= 0 && curr < n) {
            if (nums[curr] == 0) {
                curr += dir;  // move in the same direction
            } else { // nums[curr] > 0
                nums[curr]--; // decrement value
                dir = -dir;   // reverse direction
                curr += dir;  // move in new direction
            }
        }

        return allZero(nums);
    }

    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (canMakeAllZero(nums, i, 1)) count++;   // move right
                if (canMakeAllZero(nums, i, -1)) count++;  // move left
            }
        }
        return count;
    }
};
