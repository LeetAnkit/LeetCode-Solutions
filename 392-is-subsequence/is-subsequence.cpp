class Solution {
public:
    bool isSubsequence(string s, string t) {

        int n = s.size();
        int m = t.size();

        stack<int>st;
        

        for( int i =n -1 ; i>=0 ; i--){
            st.push(s[i]);
        }
        for( int j =0; j<m; j++){
           
           if(!st.empty() && t[j] == st.top()){
            st.pop();
           }

        }
       return st.empty(); 
    }
};