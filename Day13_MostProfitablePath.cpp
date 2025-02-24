class Solution {
    bool findBobPath(vector<vector<int>>& tree, int node, int parent, int time,
                     vector<int>& bobTime) {
        bobTime[node] = time;
        if (node == 0)
            return true;

        for (int neighbor : tree[node]) {
            if (neighbor == parent)
                continue;
            if (findBobPath(tree, neighbor, node, time + 1, bobTime))
                return true;
        }

        bobTime[node] = -1;
        return false;
    }

    int dfs(vector<vector<int>>& tree, vector<int>& amount, int node,
            int parent, int time, vector<int>& bobTime,
            vector<int>& aliceTime) {
        aliceTime[node] = time;
        int netGain = 0;

        if (bobTime[node] == -1 || time < bobTime[node]) {
            netGain = amount[node]; 
        } else if (time == bobTime[node]) {
            netGain = amount[node] / 2;
        }

        int maxProfit = INT_MIN;
        bool isLeaf = true;

        for (int neighbor : tree[node]) {
            if (neighbor == parent)
                continue;
            isLeaf = false;
            maxProfit = max(maxProfit, dfs(tree, amount, neighbor, node,
                                           time + 1, bobTime, aliceTime));
        }

        return netGain + (isLeaf ? 0 : maxProfit);
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> tree(n);

        for (auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        vector<int> bobTime(n, -1);
        vector<int> aliceTime(n, -1);
        vector<bool> visited(n, false);

        int time = 0;
        findBobPath(tree, bob, -1, time, bobTime);

        return dfs(tree, amount, 0, -1, 0, bobTime, aliceTime);
    }
};
