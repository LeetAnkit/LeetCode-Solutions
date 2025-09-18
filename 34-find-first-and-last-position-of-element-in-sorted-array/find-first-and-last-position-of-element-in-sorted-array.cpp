class Solution {


 private :
       int findBound(vector<int>&nums, int target, bool isFirst){
        int lo =0;
        int hi = nums.size() -1;
        int bound = -1;

        while(lo<=hi){
            int mid = lo+ (hi -lo)/2;
            if(nums[mid] == target){
                bound = mid;
                if(isFirst){
                    hi =mid-1;
                }
                else{
                    lo = mid+1;
                }
                
            }else if(nums[mid] < target){
                 lo = mid+1;
            }
            else{
                hi = mid -1;
            }
        }
        return bound;
       }
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int first = findBound(nums, target, true);
        int last = findBound(nums, target, false);
        return {first, last};
        
    }
};