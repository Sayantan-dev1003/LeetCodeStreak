class Solution {
public:
    string makeFancyString(string s) {
        string result;

        for (char c : s) {
            int len = result.size();
            if (len >= 2 && result[len - 1] == c && result[len - 2] == c) {
                continue;
            }
            result += c;
        }

        return result;
    }
};
