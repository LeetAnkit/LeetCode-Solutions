class Solution {

    private:

      void dfs( int node,vector<vector<int>>& adjLis , vector<int>&vis){

        vis[node] =1;
        for( auto ele : adjLis[node]){
            if(!vis[ele]){
                dfs( ele, adjLis, vis);
            }
        }

      }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>> adjLis(n);

       // changing the adjacency
       for( int i=0;i< n ; i++){
        for( int j =0; j< n ; j++){
            if(isConnected[i][j] == 1 && i!=j){
                adjLis[i].push_back(j);
                adjLis[j].push_back(i);
            }
        }
       }

       vector<int> vis(n, 0);
       int count =0;

       for( int i =0 ; i< n ; i++){
        if( !vis[i]){
            count++;
            dfs(i, adjLis, vis);

        }
       }
       return count;



        
    }
};