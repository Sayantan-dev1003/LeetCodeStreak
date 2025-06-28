class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
    vector<pair<int, int>> indexed;

    for (int i = 0; i < n; ++i) {
        indexed.push_back({nums[i], i});
    }

    sort(indexed.begin(), indexed.end(), [](auto &a, auto &b) {
        return a.first > b.first;
    });

    vector<pair<int, int>> topK(indexed.begin(), indexed.begin() + k);

    sort(topK.begin(), topK.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });

    vector<int> result;
    for (auto &p : topK) {
        result.push_back(p.first);
    }

    return result;
    }
};
