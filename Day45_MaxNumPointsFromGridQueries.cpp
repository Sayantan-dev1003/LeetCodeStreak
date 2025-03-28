class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        vector<int> answer(queries.size(), 0);
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        vector<pair<int, int>> query_indices;
        for (int i = 0; i < queries.size(); ++i) {
            query_indices.push_back({queries[i], i});
        }
        sort(query_indices.begin(), query_indices.end());

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        vector<int> directions = {-1, 0, 1, 0, -1};
        int count = 0;
        int index = 0;

        for (auto [query, idx] : query_indices) {
            while (!pq.empty() && pq.top().first < query) {
                auto [val, pos] = pq.top();
                pq.pop();
                int x = pos.first, y = pos.second;
                count++;

                for (int d = 0; d < 4; ++d) {
                    int nx = x + directions[d], ny = y + directions[d + 1];
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny]) {
                        pq.push({grid[nx][ny], {nx, ny}});
                        visited[nx][ny] = true;
                    }
                }
            }
            answer[idx] = count;
        }

        return answer;
    }
};
