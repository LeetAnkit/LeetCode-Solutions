class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin() , nums.end());

        int maxCount =0;

        for( auto num : st){
            if(st.find(num-1) == st.end()){
                int currentNum = num;
                int currentCount =1;

                while(st.find(currentNum +1) != st.end()){
                    currentNum++;
                    currentCount++;
                }

                maxCount = max(maxCount, currentCount);
            }
        }

        return maxCount;
        
    }
};