class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {

        int zeroCount = k;

        for( int num :  nums){
            if(num ==1){
                if( zeroCount < k){
                    return false;
                }
                zeroCount =0;
            }else{
                zeroCount++;
            }
        }


        return true;

       
        
    }
};