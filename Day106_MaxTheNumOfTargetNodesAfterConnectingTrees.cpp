class Solution {
private:
    int bfs(vector<vector<int>>& r1, int k, int i, int n) {
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(i);
        int dist = 0;
        int cnt = 0;
        visited[i] = true;
        while (!q.empty() && dist <= k) {
            int n1 = q.size();
            while (n1--) {
                int temp = q.front();
                q.pop();
                cnt++;
                for (int v : r1[temp]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            dist++;
        }
        return cnt;
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int n = edges1.size();
        int m = edges2.size();
        vector<vector<int>> r1(n + 1, vector<int>()), r2(m + 1, vector<int>());
        for (vector<int>& ans : edges1) {
            r1[ans[0]].push_back(ans[1]);
            r1[ans[1]].push_back(ans[0]);
        }
        for (vector<int>& ans : edges2) {
            r2[ans[0]].push_back(ans[1]);
            r2[ans[1]].push_back(ans[0]);
        }
        vector<int> curr(n + 1);
        for (int i = 0; i <= n; i++) {
            curr[i] = bfs(r1, k, i, n + 1);
        }
        int dc = 0;
        for (int i = 0; i <= m; i++) {
            dc = max(dc, bfs(r2, k - 1, i, m + 1));
        }
        vector<int> ans;
        for (int i = 0; i <= n; i++) {
            ans.push_back(curr[i] + dc);
        }
        return ans;
    }
};
