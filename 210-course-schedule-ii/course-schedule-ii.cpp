class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(N);
        for (auto& ele : prerequisites) {
            adj[ele[1]].push_back(ele[0]);
        }

        vector<int> indegree(N, 0);
        for (int i = 0; i < N; i++) {
            for (int it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (int it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return topo.size() == N ? topo : vector<int>();
    }
};
