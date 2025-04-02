class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        

        int n = nums.size();
        if(n < 3){
            return 0;
               
        }
    
        long long  maxValue =0;
        for( int i =0 ; i< n-2; i++){
            for( int j =i+1 ; j< n-1 ; j++){
                for( int k=j+1 ; k < n ; k++){
                    long long check= (long long)(nums[i] - nums[j]) * nums[k];

                    if(check > 0){
                        maxValue = max( maxValue, check);
                    }
                }
            }

        }
        return maxValue;
    }
};