class Solution {
private:
    pair<int, int> getCoordinates(int square, int n) {
        int r = (square - 1) / n;
        int c = (square - 1) % n;
        int row = n - 1 - r;
        int col = (r % 2 == 0) ? c : n - 1 - c;
        return {row, col};
    }

public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        queue<pair<int, int>> q;
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, moves] = q.front();
            q.pop();

            if (curr == n * n)
                return moves;

            for (int i = 1; i <= 6 && curr + i <= n * n; ++i) {
                int next = curr + i;
                auto [row, col] = getCoordinates(next, n);

                if (board[row][col] != -1)
                    next = board[row][col];

                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }
        return -1;
    }
};
