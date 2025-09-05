class Solution {
public:
    void reverseString(vector<char>& s) {

        int last_ptr = s.size()-1;
        int i =0;
        
        while( i <=last_ptr ){
            swap(s[i] , s[last_ptr]);
            

            i++;
            last_ptr--;
        }

       
        
    }
};