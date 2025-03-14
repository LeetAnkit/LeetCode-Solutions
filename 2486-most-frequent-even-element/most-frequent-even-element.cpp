class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        
        int  n = nums.size();
        unordered_map<int , int> mp;
        for( auto ele : nums){
            mp[ele]++;
        }

        int maxi = INT_MIN;

        int ans = -1;

        for( auto it : mp){
            int freq = it.second;
            int num = it.first;

            if(num % 2 == 0){
                if(freq > maxi || (freq == maxi && num < ans )){
                    maxi = freq;
                    ans=num;
                }
            }
        }
        return ans;
    }
};