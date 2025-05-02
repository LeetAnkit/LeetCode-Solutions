class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> mp;

        for( auto ele : s){
            mp[ele]++;
        }

      priority_queue<pair<int, char>> maxHeap;
      for( auto it : mp){
        maxHeap.push({it.second , it.first});
      }

      string result="";

      while( !maxHeap.empty()){
        auto[count, ch]= maxHeap.top();
        maxHeap.pop();
        result += string(count,ch);
      }

        
        
        
        return result;
    }
};