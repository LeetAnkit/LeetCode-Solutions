class Solution {
public:
    string getHint(string secret, string guess) {

        int n = secret.size();
        int m = guess.size();
        int bulls =0;
        int cows =0;

         vector<int> basketA(10, 0);
         vector<int> basketB(10, 0);


        for( int i =0 ; i<n ; i++ ){
           if( secret[i] == guess[i]){
            bulls++;
           }
           else{

            basketA[secret[i] - '0']++;
            basketB[guess[i] -'0']++;


           }
        }
        for(int j =0 ; j< 10 ; j++){
            cows+= min(basketA[j], basketB[j]);

        }

        return to_string(bulls)+ "A" + to_string(cows) +"B";
        
    }
};