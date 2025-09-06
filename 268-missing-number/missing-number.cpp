class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                return i;   // found the missing number
            }
        }
        return n;  // if all 0..n-1 are present, missing is n
    }
};
