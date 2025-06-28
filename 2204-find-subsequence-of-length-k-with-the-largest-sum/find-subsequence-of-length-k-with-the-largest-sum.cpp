class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        unordered_map<int, int> freq;
        vector<pair<int, int>> numIndex;

        for(int i =0 ; i< nums.size() ; i++){
            numIndex.push_back({nums[i], i});
        }

        sort(numIndex.rbegin(), numIndex.rend());

        for(int i=0; i< k ; i++){
            freq[numIndex[i].second] = numIndex[i].first;
        }

        vector<int>result;
        for(int i =0; i<nums.size();i++){
            if(freq.count(i)){
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};