class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();

        // Pair each element with its original index
        vector<pair<int, int>> nums;
        for (int i = 0; i < n; i++) {
            nums.push_back({arr[i], i});
        }

        // Sort based on value
        sort(nums.begin(), nums.end());

        int left = 0, right = n - 1;

        while (left < right) {
            int sum = nums[left].first + nums[right].first;

            if (sum == target) {
                return {nums[left].second, nums[right].second};
            } 
            else if (sum < target) {
                left++;
            } 
            else {
                right--;
            }
        }

        return {};
    }
};