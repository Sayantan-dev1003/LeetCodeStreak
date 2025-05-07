class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();

        // Step 1: Initialize distance matrix with max values
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0; // Starting point at time 0

        // Step 2: Use tuple instead of vector to allow structured bindings
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0}); // Format: {currentTime, row, col}

        // Step 3: Directions for moving in 4 directions
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        // Step 4: Process nodes while queue is not empty
        while (!pq.empty()) 
        {
            auto [time, x, y] = pq.top(); pq.pop();

            // Step 5: Check if destination reached
            if (x == m - 1 && y == n - 1)
            {
                return time;
            }

            // Step 6: Traverse all neighbors
            for (auto& dir : dirs) 
            {
                int nx = x + dir[0];
                int ny = y + dir[1];

                // Step 7: Check boundaries
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) 
                {
                    // Step 8: Compute wait time if needed
                    int waitTime = max(0, moveTime[nx][ny] - time);
                    int arriveTime = time + 1 + waitTime;

                    // Step 9: Update distance and queue if this path is better
                    if (arriveTime < dist[nx][ny]) 
                    {
                        dist[nx][ny] = arriveTime;
                        pq.push({arriveTime, nx, ny});
                    }
                }
            }
        }

        // Step 10: If unreachable
        return -1;
    }
};
