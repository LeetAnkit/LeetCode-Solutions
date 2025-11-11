class Solution {
public:
    int minAddToMakeValid(string s) {

        int open_bracket =0;
        int closed_bracket =0;

        for( int i =0 ; i< s.size() ; i++){
            if( s[i] =='('){
                open_bracket++;
            }

            else{
                if(open_bracket> 0){
                    open_bracket--;
                }
                else{
                    closed_bracket++;
                }
            }
        }

        return open_bracket + closed_bracket;

        
    }
};