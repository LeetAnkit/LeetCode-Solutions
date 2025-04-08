class Solution {
public:
    int minimumOperations(vector<int>& nums) {


    
        int count =0;

        while(true){
            set<int> unique( nums.begin(), nums.end());

        if( unique.size() == nums.size()){
            break;
        
        
        }

        nums.erase( nums.begin() , nums.begin() + min(3, (int)nums.size()));

        count++;
        }

       

        return count ;

        
    }
};