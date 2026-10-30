class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int, int>>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }
        


        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        

        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
        
        dist[0][1] = 0;
        pq.push({0, 0, 1});
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int d = curr[0];
            int u = curr[1];
            int cnt = curr[2];
            

            if (d > dist[u][cnt]) {
                continue;
            }
            

            if (u == n - 1) {
                return d;
            }
            
            for (const auto& [v, w] : graph[u]) {

                int nextCnt = (labels[u] == labels[v]) ? cnt + 1 : 1;
                

                if (nextCnt > k) {
                    continue;
                }
                

                if (dist[v][nextCnt] > d + w) {
                    dist[v][nextCnt] = d + w;
                    pq.push({dist[v][nextCnt], v, nextCnt});
                }
            }
        }
        
        return -1;
    }
};