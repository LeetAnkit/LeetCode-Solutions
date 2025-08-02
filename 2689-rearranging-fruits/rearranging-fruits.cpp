class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {

        unordered_map<int, int> b1, b2, total_freq;
        long long minCost = LLONG_MAX;

        for (auto ele : basket1) {
            b1[ele]++;
            total_freq[ele]++;
            minCost = min(minCost, (long long)ele);
        }

        for (auto it : basket2) {
            b2[it]++;
            total_freq[it]++;
            minCost = min(minCost, (long long)it);
        }

        for (auto it : total_freq) {
            if (it.second % 2 != 0) return -1;
        }

        vector<int> excess;

        for (auto cost : total_freq) {
            int diff = b1[cost.first] - b2[cost.first];
            if (diff > 0) {
                for (int i = 0; i < diff / 2; i++) {
                    excess.push_back(cost.first);
                }
            }
        }

        for (auto cost : total_freq) {
            int diff = b2[cost.first] - b1[cost.first];
            if (diff > 0) {
                for (int i = 0; i < diff / 2; i++) {
                    excess.push_back(cost.first);
                }
            }
        }

        sort(excess.begin(), excess.end());

        long long totalCost = 0;
        int half = excess.size() / 2;

        for (int i = 0; i < half; i++) {
            totalCost += min((long long)excess[i], 2 * minCost);
        }

        return totalCost;
    }
};
