class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& prerequisites) {

        // first we have to make the adjancency List

        vector<vector<int>>adj(N);
        for(auto it : prerequisites){
            adj[it[0]].push_back(it[1]);

        }
       // making the indegree list

        vector<int> indegree(N, 0);

        for( int i=0 ; i< N ; i++){
            for( auto it : adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for( int i =0 ; i< N ; i++){
            if(indegree[i] ==0){
                q.push(i);

            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            //node is in your topo sort
            // so please remove it from the indegree

            for( auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] ==0) q.push(it);

            }
        }
        if( topo.size() == N) return true;
        return false;
        
    }
};