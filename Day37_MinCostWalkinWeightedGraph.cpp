class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<int> component(n, -1);
        vector<int> minCost(n, INT_MAX);
        int compID = 0;

        function<void(int, int)> dfs = [&](int node, int currAND) {
            component[node] = compID;
            minCost[node] = currAND;
            for (auto& [neighbor, weight] : graph[node]) {
                int newAND = currAND & weight;
                if (component[neighbor] == -1 || newAND < minCost[neighbor]) {
                    dfs(neighbor, newAND);
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (component[i] == -1) {
                dfs(i, INT_MAX);
                compID++;
            }
        }

        vector<int> answer;
        for (auto& q : query) {
            int s = q[0], t = q[1];
            if (component[s] == component[t]) {
                answer.push_back(minCost[t]);
            } else {
                answer.push_back(-1);
            }
        }

        return answer;
    }
};
