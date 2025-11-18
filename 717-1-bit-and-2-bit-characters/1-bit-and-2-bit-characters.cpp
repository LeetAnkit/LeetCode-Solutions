class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        int n = bits.size();
        
        while (i < n - 1) {
            if (bits[i] == 1) {
                i += 2; // skip 2-bit character
            } else {
                i += 1; // skip 1-bit character
            }
        }
        
        return i == n - 1; // true if last character is 1-bit
    }
};