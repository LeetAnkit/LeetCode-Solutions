class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {

        int sum = 0;
        vector<int> rem1; // nums % 3 == 1
        vector<int> rem2; // nums % 3 == 2

        // 1️⃣ Calculate sum and track numbers by remainder
        for(int x : nums){
            sum += x;
            if(x % 3 == 1) rem1.push_back(x);
            else if(x % 3 == 2) rem2.push_back(x);
        }

        // 2️⃣ If already divisible, return
        if(sum % 3 == 0) return sum;

        int rem = sum % 3;

        // Sort to easily get smallest numbers
        sort(rem1.begin(), rem1.end());
        sort(rem2.begin(), rem2.end());

        int option1 = INT_MAX, option2 = INT_MAX;

        // 3️⃣ Try removing numbers to fix remainder
        if(rem == 1){
            // Option 1: remove smallest number with rem1
            if(rem1.size() >= 1) option1 = rem1[0];

            // Option 2: remove two smallest with rem2
            if(rem2.size() >= 2) option2 = rem2[0] + rem2[1];
        }
        else { // rem == 2
            if(rem2.size() >= 1) option1 = rem2[0];
            if(rem1.size() >= 2) option2 = rem1[0] + rem1[1];
        }

        int minSubtract = min(option1, option2);
        if(minSubtract == INT_MAX) return 0; // No valid removal → best is 0

        return sum - minSubtract;
    }
};
