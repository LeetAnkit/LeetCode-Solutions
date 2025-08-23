class Solution {

    private:

      bool dfs( int node , int col, vector<int>& color, vector<vector<int>>& adj){
        color[node] = col;

        for( auto ele : adj[node]){
            if(color[ele] == -1){
                if( dfs(ele, !col, color, adj) == false) return false;
            }
            else if(color[ele] == col){
                return false;
            }
        }
        return true;
      }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
       int n = graph.size();
       vector<int> color(n , -1);

       for( int i=0 ; i< n ; i++){
        if( color[i] == -1){
            if( dfs(i, 0, color, graph) == false) return false;
        }
       }

       return true;
        
    }
};