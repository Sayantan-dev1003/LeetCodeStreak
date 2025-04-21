class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long minVal = 0, maxVal = 0, curr = 0;

        for (int diff : differences) {
            curr += diff;
            minVal = min(minVal, curr);
            maxVal = max(maxVal, curr);
        }

        long startMin = lower;
        long startMax = upper - (maxVal - minVal);

        long count = startMax - startMin + 1;

        return count > 0 ? count : 0;
    }
};
