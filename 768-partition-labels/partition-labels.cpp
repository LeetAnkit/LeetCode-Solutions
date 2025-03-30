class Solution {
public:
    vector<int> partitionLabels(string s) {

        //we have to find the last occurence of the Each Character we use map for his
       int n = s.size();
       unordered_map<char, int> lastOcc;
       for( int i =0 ; i< n ; i++){
             lastOcc[s[i]] = i;
       }

       //traversing the string to Partion it

       vector<int> result;

       int maxIndex =0, partitionStart =0;

       for( int i =0 ; i < s.size(); i++){

        maxIndex = max(maxIndex , lastOcc[s[i]]);

        //if the current index matches the max Index , then we found our partion

        if( i== maxIndex){
            result.push_back(i-  partitionStart +1);
             partitionStart = i+1;
        }

       }
        
        return result;


        
    }
};