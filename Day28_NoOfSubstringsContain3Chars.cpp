class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        unordered_map<char, int> freq;
        int left = 0, count = 0;

        for (int right = 0; right < n; right++) {
            freq[s[right]]++;

            while (freq['a'] > 0 && freq['b'] > 0 && freq['c'] > 0) {
                count += (n - right);
                freq[s[left]]--;
                left++;
            }
        }
        return count;
    }
};
