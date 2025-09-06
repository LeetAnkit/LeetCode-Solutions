class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = -1;

        // Step 1: find first zero
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                j = i;
                break;
            }
        }

        // No zero found → already done
        if (j == -1) return;

        // Step 2: shift non-zeros forward
        for (int i = j + 1; i < n; i++) {   // ✅ fixed loop condition
            if (nums[i] != 0) {
                swap(nums[j], nums[i]);
                j++;
            }
        }
    }
};
