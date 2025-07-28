class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {


        int left =0;
        int ans =0;
        int count =0;
        int i =0;

        for (  int j =0 ; j< nums.size() ; j++){
            if(nums[j] % 2 !=0 ) count++, left =0;

            while( count == k ){
             
                if(nums[i] % 2 !=0) count--;
                i++, left++;
            }
             ans+=left;
            
        }
       return ans;
        
    }
};