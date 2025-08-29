class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();   
        if (grid[0][0] != 0 || grid[n - 1][m - 1] != 0) return -1;

        pair<int, int> source = {0, 0};
        pair<int, int> destination = {n - 1, m - 1};

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[source.first][source.second] = 1;
        q.push({1, {source.first, source.second}});

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (r == destination.first && c == destination.second) return dis;

            for (int i = 0; i < 8; i++) {
                int newr = r + dr[i];
                int newc = c + dc[i];

                if (newr >= 0 && newr < n && newc >= 0 && newc < m &&
                    grid[newr][newc] == 0 && dist[newr][newc] > dis + 1) {
                    dist[newr][newc] = dis + 1;
                    q.push({dis + 1, {newr, newc}});
                }
            }
        }

        return -1;
    }
};
