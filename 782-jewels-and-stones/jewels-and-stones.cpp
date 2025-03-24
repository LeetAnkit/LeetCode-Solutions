class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans =0;
        unordered_map<char, int> mp;

        for( auto ele : stones){
            mp[ele]++;
        }

        for(auto it : jewels){
            ans+=mp[it];
        }
        return ans;
        


        
    }
};