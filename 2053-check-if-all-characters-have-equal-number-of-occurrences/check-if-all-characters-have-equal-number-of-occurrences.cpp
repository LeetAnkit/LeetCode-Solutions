class Solution {
public:

   //Easiest Solution Ever

    bool areOccurrencesEqual(string s) {

       unordered_map<char , int> mp;

     for ( char &c : s){
        mp[c]++;
     }

        int  ct = mp[s[0]];

        for( int i =0 ; i< s.length() ; i++){
            if(mp[s[i]] != ct) return false;
        }
        return true;  
    }
};