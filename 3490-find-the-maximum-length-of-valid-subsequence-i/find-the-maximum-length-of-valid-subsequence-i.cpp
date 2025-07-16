class Solution {
public:
    int maximumLength(vector<int>& nums) {

    int n = nums.size();

     int Even =0;
     int Odd =0;

     for( int &ele : nums){
        if(ele %2 ==0){
            Even++;
        }
        else{
            Odd++;
        }
     }
    int parity = nums[0] % 2;
    int alternate = 1;
     for(int i = 1 ; i< n ; i++){
        int currParity = nums[i] % 2;
        if(currParity != parity){
            alternate++;
            parity = currParity; 
        }
     }


     return max({Even, Odd, alternate});

     


        
    }
};