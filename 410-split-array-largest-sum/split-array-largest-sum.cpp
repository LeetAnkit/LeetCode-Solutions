class Solution {



public:

   bool canSplit( vector<int> &nums, int k, int maxSumAllowed){
    int subarray =1;
    int currSum =0;

    for(int num : nums){
        if(currSum + num > maxSumAllowed){
            subarray++;
            currSum = num;
        }
        else{
            currSum +=num;
        }
    }
    return subarray <=k;
   }

    int splitArray(vector<int>& nums, int k) {

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        int result = high;

        while( low <= high){
            int mid = low + ( high - low )/2;
    
        if(canSplit(nums, k, mid)){
            result = mid;
            high = mid - 1;
        }
        else{
            low = mid+1;
        }
        }

        return result;
        
    }
};