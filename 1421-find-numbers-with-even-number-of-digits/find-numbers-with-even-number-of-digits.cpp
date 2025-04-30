class Solution {
public:

    int countDigits(int digit){
        if (digit == 0) return 1;

        int count = 0;
        while(digit != 0){
            digit= digit/10;
            count++;
        }
        return count;
    }
    int findNumbers(vector<int>& nums) {
      int n = nums.size();

      int ans =0;

      for( int i =0; i< n ; i++){
        int count= countDigits(nums[i]);
        if( count % 2 == 0){
            ans++;
        }
        else{
            continue;
        }
      }

      return ans;
        
    }
};