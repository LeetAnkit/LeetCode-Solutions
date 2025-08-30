class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto &it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]}); // undirected
        }

        using P = pair<long long,int>; // {dist, node}
        priority_queue<P, vector<P>, greater<P>> pq;

        vector<long long> dis(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dis[0] = 0;
        ways[0] = 1;
        pq.push({0,0});

        int mod = 1e9+7;

        while(!pq.empty()){
            auto [currDis, node] = pq.top();
            pq.pop();

            if(currDis > dis[node]) continue;

            for(auto &it : adj[node]){
                int adjNode = it.first;
                long long edW = it.second;

                if(currDis + edW < dis[adjNode]){
                    dis[adjNode] = currDis + edW;
                    pq.push({dis[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(currDis + edW == dis[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1] % mod;
    }
};
