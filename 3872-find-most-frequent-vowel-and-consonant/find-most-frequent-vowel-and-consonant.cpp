class Solution {
public:
      bool isVowel(char c ){
        return( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
        
      }
    int maxFreqSum(string s) {

        int n = s.size();
        int maxVowels =0;
        int maxConst = 0;
        

        unordered_map<char, int> mp;

        for( auto& ele : s){
            mp[ele]++;
        }

        for(auto &pair : mp){
            char key = pair.first;
            int value = pair.second;

            if(isVowel(key)){
                maxVowels = max(pair.second, maxVowels);
            }
            else{
                 maxConst = max(pair.second, maxConst);
            }
        }

       return {maxVowels + maxConst};

       
        
    }
};