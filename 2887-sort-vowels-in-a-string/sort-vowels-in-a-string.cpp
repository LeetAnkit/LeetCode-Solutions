class Solution {



public:

     bool isVowels( char c){
        return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c=='U' ||  
        c == 'a' || c=='e' || c=='i'  || c=='o' || c=='u');

     }

    string sortVowels(string s) {

        int n = s.size();
   
        vector<int> positions;
        vector<char> vowels;

        for( int i =0; i<n ; i++){
            if(isVowels(s[i]) ){
                positions.push_back(i);
                vowels.push_back(s[i]);
            }
        }

        sort(vowels.begin(), vowels.end());

        for( int i =0 ; i< positions.size() ; i++){
            s[positions[i]] = vowels[i];
        }



        return s;



        
        
    }
};