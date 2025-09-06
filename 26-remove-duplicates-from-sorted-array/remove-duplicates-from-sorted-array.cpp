class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       //  first replacing all the same coming elements by INT_MAX// you can also represent as INT_MIN
        for ( int i =1 ; i< nums.size(); i++){
            if (nums[i]== nums[i-1]){
                nums[i-1] = INT_MAX;
            }
        }
        // for sorting purpose 
        sort (nums.begin() , nums.end());

        
        int count=0;
        for( int i=0; i<nums.size () ; i++){
            if ( nums[i]!=  INT_MAX) count++;

        }
        return count;

    }
};