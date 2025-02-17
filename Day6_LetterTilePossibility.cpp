class Solution {
    void backtrack(unordered_map<char, int>& freq, int& count, int length) {
        for (auto& [ch, f] : freq) {
            if (f > 0) {
                count++;
                freq[ch]--;
                backtrack(freq, count, length + 1);
                freq[ch]++;
            }
        }
    }

public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        for (char ch : tiles) {
            freq[ch]++;
        }
        int count = 0;
        backtrack(freq, count, 0);
        return count;
    }
};
