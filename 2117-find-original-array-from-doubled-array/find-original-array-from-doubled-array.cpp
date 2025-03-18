class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {

        int n= changed.size();

        if( n % 2 !=0){
            return {};
        }

        sort(changed.begin() , changed.end());

        unordered_map<int , int>mp;

        for( auto ele : changed){
            mp[ele]++;
        }

        vector<int> result;

        for( auto ele : changed){
            if(mp[ele] == 0){
            continue;
        }
            int twice = 2*ele;
             if(mp.find(twice ) == mp.end() || mp[twice] == 0){
            return {};
        }
      

      else{
        result.push_back(ele);
         mp[ele]--;
         mp[twice]--;
      }
        }

        

       


     

    return result;
        
        
    }
};