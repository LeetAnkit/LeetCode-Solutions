class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {

        int n = nums.size();
        long long maxValue = 0;

        vector<int> maxLeft(n, 0);
            maxLeft[0] = nums[0];

            for( int j =1 ; j< n ; j++){
                maxLeft[j] = max(maxLeft[j-1] , nums[j-1]);
            }
        vector<int>maxRight(n, 0);
            maxRight[n-1] = nums[n-1];

            for( int j = n-2 ; j>=0 ; j--){
                maxRight[j] = max(maxRight[j+1] , nums[j+1]);
            }


            for( int j =1;j<n-1 ; j++){
                long long value = (long long) (maxLeft[j] - nums[j])*maxRight[j];

                maxValue = max( maxValue, value);
            }
        return maxValue;

        // maxLeft for  

        
    }
};