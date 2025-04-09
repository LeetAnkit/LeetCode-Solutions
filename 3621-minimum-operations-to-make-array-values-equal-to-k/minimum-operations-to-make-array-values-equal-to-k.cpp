class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int op =0;
        set<int> st;

        for( auto ele : nums){
            if(ele<k) return -1;
            else if ( ele!=k)st.insert(ele);
        }
        return st.size();
        
        
    }
};