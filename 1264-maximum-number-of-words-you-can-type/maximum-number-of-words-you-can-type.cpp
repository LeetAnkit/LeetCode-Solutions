class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        

        // first i am splitting all the words from the text

        stringstream ss(text);
        string word;
      
          unordered_set<char> brokenSet(brokenLetters.begin(), brokenLetters.end()); 
        int count =0;
        while( ss >> word){
        bool isBroken = false;
        for(char c : word){
            if(brokenSet.count(c)){
            isBroken = true;
            break;

            }
           
        }
        if( !isBroken) count++;
    }

        
        return count;
     
    }

};