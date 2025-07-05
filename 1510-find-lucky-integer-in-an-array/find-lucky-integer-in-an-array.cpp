class Solution {
public:
    int findLucky(vector<int>& arr) {

        unordered_map<int, int> mp;

        for(auto ele : arr){
            mp[ele]++;
        }
         int result = -1;
        for(auto& itr : mp){
            if(itr.first == itr.second){
              result = max(result, itr.first);
            }
            
        }
        return result;
    }
};