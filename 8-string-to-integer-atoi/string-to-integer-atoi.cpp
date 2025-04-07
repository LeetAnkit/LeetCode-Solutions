class Solution {
public:
    int myAtoi(string s) {

        stringstream ss(s);
        long long result =0;

        int sign =1 ;
        char c;

        while(ss.peek() == ' ')ss.get();

        if(ss.peek() == '-' || ss.peek() == '+'){
            c= ss.get();
            sign = ( c== '-')? -1 : 1;
        }
         while ( ss.peek () >='0' && ss.peek() <='9'){
            c=ss.get();
            result = result * 10 + (c-'0');
           //

           //Clamp to 32 bit range if overflow occurs;
            if( result * sign <=INT_MIN) return INT_MIN;
            if( result * sign >= INT_MAX) return INT_MAX;
         }
          // it will return the  result with the proper sign
         return static_cast<int>(result * sign);
        
    }
};