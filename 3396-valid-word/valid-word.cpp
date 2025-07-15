class Solution {
public:
    bool isValid(string word) {
    
     // we have to check three conditions
    //  minmum size should be 3 
    //  0-9
    //  one vowel. and one constant


    int n = word.size();
    if(n < 3) return false;
    int vowels =0, constants =0;
    string vowelList = "aeiouAEIOU";


    for( char ele : word){
      if(isalpha(ele)){
        if(vowelList.find(ele) != string::npos){
            vowels++;
        }
        else{
            constants++;
        }
      }else if(!isdigit(ele)){
        return false;
      }
    }

    return vowels >=1 && constants >=1;

     
        
    }
};