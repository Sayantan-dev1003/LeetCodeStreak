class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> indices;
        int count = 0;

        for (int i = 0; i < nums.size(); ++i) {
            indices[nums[i]].push_back(i);
        }

        for (auto& [num, idxs] : indices) {
            for (int i = 0; i < idxs.size(); ++i) {
                for (int j = i + 1; j < idxs.size(); ++j) {
                    if ((idxs[i] * idxs[j]) % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
