class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<vector<int>>adjRev(N);
        vector<int>indegree(N, 0);

        // here i have to push the revesres of the Adjancency List
        for( int  i =0 ; i< N ; i++){
            // i -> it  // in rest of the Questions we are dong this so this time Reverse
            // it -> i for the reversing
            for( auto it : graph[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        vector<int> safeNodes;
      // checking for  0 indegree
        for( int i =0 ; i< N  ; i++){
            if(indegree[i] == 0){
                q.push(i);

            }
        }

        while( !q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for( auto it : adjRev[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);

            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
        
    }
};