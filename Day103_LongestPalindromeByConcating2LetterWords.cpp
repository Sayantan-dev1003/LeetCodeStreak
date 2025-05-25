class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> count;
        int length = 0;
        bool hasCenter = false;

        for (const string& word : words) {
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (count[rev] > 0) {
                length += 4;
                count[rev]--;
            } else {
                count[word]++;
            }
        }

        for (auto& [word, freq] : count) {
            if (word[0] == word[1] && freq > 0) {
                hasCenter = true;
                break;
            }
        }

        if (hasCenter)
            length += 2;

        return length;
    }
};
