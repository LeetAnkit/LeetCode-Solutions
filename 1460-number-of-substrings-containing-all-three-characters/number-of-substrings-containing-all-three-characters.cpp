class Solution {
public:
    int numberOfSubstrings(string s) {


        int n = s.size();
        unordered_map<char, int> mp;
        int count =0;

        int i =0;
        int j =0;

        for( int j =0; j < n ; j++){
            mp[s[j]]++;
        

        while( mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0 ){
            count+= s.size() -j ;
            mp[s[i]]--;
            i++;
        }
        }
        return count;
 
        
    }
};