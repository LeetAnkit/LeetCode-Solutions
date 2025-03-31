class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {

       int n = weights.size();
        long long maxi =0 , mini =0;
       if( n <=2) {
        return 0;
       }

         vector<int> temp;

         for( int i =0 ; i< n-1 ; i++){
            temp.push_back(weights[i] +weights[i+1]);


         }
         sort(temp.begin() , temp.end());
        int m = temp.size();
         for (int i =0 ; i< k-1 ; i++){
            mini += temp[i];
            maxi += temp[m-1-i];
         }

         return maxi - mini;
       // for minimum 
         
       
        
    }
};