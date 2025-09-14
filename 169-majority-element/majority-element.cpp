class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        int times =n/2;

        unordered_map<int, int> mp;

        for( auto ele : nums){
            mp[ele]++;
            if(mp[ele] > times){
                return  ele ;
            }
        }
        return -1;

        
        
    }
};