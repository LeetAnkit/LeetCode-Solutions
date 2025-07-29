class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;
        
        for (int point : cardPoints) {
            total += point;
        }

        // Window size of cards we're NOT picking
        int windowSize = n - k;
        int minSum = 0;
        
        for (int i = 0; i < windowSize; ++i) {
            minSum += cardPoints[i];
        }
        
        int currSum = minSum;
        for (int i = windowSize; i < n; i++) {
            currSum += cardPoints[i] - cardPoints[i - windowSize];
            minSum = min(minSum, currSum);
        }
        
        return total - minSum;
    }
};
