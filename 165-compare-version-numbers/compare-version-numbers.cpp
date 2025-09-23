class Solution {

    void seprating  ( string &s , vector<int> &nums){

        // separting the given version on the basis of . and then storing into the nums
        stringstream ss(s);
        //most important command 
        string num = "";
        while(getline(ss , num , '.'))
        nums.push_back(stoi(num));
        
    }
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 ;
        vector<int> v2;

        seprating( version1 , v1);
        seprating( version2 , v2);

        int n = v1.size();
        int m = v2.size();

        int i =0 ; 
        int j =0 ;

        while( i<n && j<m){
            if (v1[i] < v2[j]){
                return -1;
            }
            else if (v1[i] > v2[j]){
                return 1;
            }
            i++;
            j++;
        }

        if ( i< n ){
            while( i< n){
                if(v1[i++] > 0){
                    return 1;
                }
            }
        }

        if ( j < m ){
            while ( j < m){
                if ( v2[j++] > 0){
                    return -1;
                }
            }
        }
        return 0;
        
        
    }
};