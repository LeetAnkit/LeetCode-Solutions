class Solution {
public:
    bool check(vector<int>& nums) {

    int count =0;
    if(nums[nums.size()-1] >  nums[0]){
        count++;
    }

    for( int i =0 ; i< nums.size()-1 ; i++){
        if(nums[i] >nums[i+1]){
            count++;
        }
    }

    


     return count<=1;

        


    }
};