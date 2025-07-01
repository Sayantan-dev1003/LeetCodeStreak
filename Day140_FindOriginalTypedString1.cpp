class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
        vector<int> groupLens;

        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && word[j] == word[i])
                ++j;
            groupLens.push_back(j - i);
            i = j;
        }

        int total = 1;

        for (int len : groupLens) {
            if (len >= 2) {
                total += (len - 1);
            }
        }

        return total;
    }
};
