class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> index_map;

        for (int i = 0; i < nums.size(); i++) {
            if (index_map.find(nums[i]) != index_map.end() &&
                (i - index_map[nums[i]]) <= k) {
                return true;
            }
            index_map[nums[i]] = i;
        }
        return false;
    }
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> elements;
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                elements.push_back(grid[i][j]);
            }
        }

        sort(elements.begin(), elements.end());
        int median = elements[elements.size() / 2];
        int operations = 0;

        for (int num : elements) {
            int diff = abs(num - median);
            if (diff % x != 0)
                return -1;
            operations += diff / x;
        }
        return operations;
    }
};
