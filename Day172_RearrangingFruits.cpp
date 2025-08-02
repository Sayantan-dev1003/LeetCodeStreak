class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;

        for (int val : basket1)
            freq[val]++;
        for (int val : basket2)
            freq[val]--;

        vector<int> excess;
        int mini = INT_MAX;

        for (auto& [key, value] : freq) {
            if (value % 2 != 0)
                return -1;
            int times = abs(value) / 2;
            while (times--)
                excess.push_back(key);
            mini = min(mini, key);
        }

        sort(excess.begin(), excess.end());

        long long cost = 0;
        int n = excess.size();
        for (int i = 0; i < n / 2; ++i) {
            cost += min(excess[i], 2 * mini);
        }

        return cost;
    }
};
