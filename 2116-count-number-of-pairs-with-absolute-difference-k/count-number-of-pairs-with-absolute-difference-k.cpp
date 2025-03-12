class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
       

       map<int, int> mpp;

       for( auto a : nums) mpp[a]++;

       int ans =0;

       for( auto ele : mpp){
            int key = ele.first +k;
            if(mpp.find(key) != mpp.end()){
                ans+=ele.second*mpp[key];
            }

       }
       return ans;
        
        
    }
};