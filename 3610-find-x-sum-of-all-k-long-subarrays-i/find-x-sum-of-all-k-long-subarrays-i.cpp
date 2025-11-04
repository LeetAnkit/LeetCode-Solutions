class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int> ans(n-k+1);
        for(int i=0;i+k<=n;i++){
            
            vector<int> sub(nums.begin()+i,nums.begin()+i+k);
            ans[i] = sumOfTopX(sub,x);           
           
        }
        return ans;
    }
private:
    int sumOfTopX(vector<int>& a,int x){
        vector<int> mp(51);

        for(auto x:a) mp[x]++;
        vector<vector<int>> v;

        for(int i=1;i<=50;i++) v.push_back({mp[i],i}); // freq,ele

        sort(v.rbegin(),v.rend());
        int sm =0;

        for(int i=0;i<x;i++){
            sm += v[i][0]*v[i][1];
        }
        return sm;
    }
};
