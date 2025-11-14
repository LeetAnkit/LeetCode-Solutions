class Solution {
public:

   string nextTerm(string &s){
    string res;
    int n = s.size();
    int i =0;

    while(i < n ){
        char ch = s[i];
        int count =1;

        while( i +1  <n && s[i+1] == ch ){
            count++;
            i++;
        }

     res+= to_string(count);
     res.push_back(ch);
     i++;
    }
    return res;
   }
    string countAndSay(int n) {

        if(  n <=0) return "";
        string term ="1";

        for( int k =2 ; k<=n ; k++){
            term = nextTerm(term);
        }

        return term;
        
    }
};