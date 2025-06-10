class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        int maxOdd = INT_MIN;
        int minEven = INT_MAX;

        for (auto& [ch, count] : freq) {
            if (count % 2 == 1) {
                maxOdd = max(maxOdd, count);
            } else {
                minEven = min(minEven, count);
            }
        }

        return maxOdd - minEven;
    }
};
