class Solution {
public:
    int longestChain(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int longest = 1, curr = 1;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1] + 1) {
                curr++;
            } else {
                longest = max(longest, curr);
                curr = 1;
            }
        }
        longest = max(longest, curr);
        return longest;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxHGap = longestChain(hBars) + 1; // removing k consecutive bars gives gap k+1
        int maxVGap = longestChain(vBars) + 1;

        int side = min(maxHGap, maxVGap);
        return side * side;  // area of the square
    }
};
