class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> count;
        for (int ans : answers) {
            count[ans]++;
        }

        int result = 0;
        for (auto& [k, v] : count) {
            int groupSize = k + 1;
            int numGroups = ceil((double)v / groupSize);
            result += numGroups * groupSize;
        }

        return result;
    }
};
