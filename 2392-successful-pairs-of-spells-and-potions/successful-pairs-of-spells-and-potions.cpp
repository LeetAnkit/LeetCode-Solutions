class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
      sort(potions.begin(), potions.end());
        int  n = spells.size();
        int  m = potions.size();
        vector<int> ans;
         int  i =0;  
         while ( i < n ){
            int spell = spells[i];
            int left =0 , right = m-1;
            int index = m ;

            while( left <= right){
                int mid = left + (right - left) /2;
                if((long long) spell * potions[mid] >= success){
                    index = mid;
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }


            ans.push_back(m- index);
            
            i++;

         }
        return ans;

         
    }
};