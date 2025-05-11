class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count =0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i =0;
        int j =0;
        while(i<s.size() && j <g.size()){
            if(s[i]>=g[j]){
                count++;
                j++;
            }
            i++;
        }
        return count;
    }
};