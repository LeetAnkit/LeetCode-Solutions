class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        int n  = arr.size();

        unordered_map<int , int> mp;

        for( auto ele  : arr){
              mp[ele]++;
        }
        unordered_map<int , int> mp2;
        for( auto it : mp){
            if( mp2[it.second]  == 1){
                return false;
            }


            mp2[it.second]++;
        }
        return true;
    }
};