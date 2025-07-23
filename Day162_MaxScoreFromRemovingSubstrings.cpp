class Solution {
public:
    int maximumGain(string s, int x, int y) {
        auto removePattern = [](string& s, char first, char second,
                                int val) -> pair<string, int> {
            string result;
            int score = 0;
            for (char c : s) {
                if (!result.empty() && result.back() == first && c == second) {
                    result.pop_back();
                    score += val;
                } else {
                    result.push_back(c);
                }
            }
            return {result, score};
        };

        int totalScore = 0;

        if (x > y) {
            auto [afterFirst, score1] = removePattern(s, 'a', 'b', x);
            auto [afterSecond, score2] = removePattern(afterFirst, 'b', 'a', y);
            totalScore = score1 + score2;
        } else {
            auto [afterFirst, score1] = removePattern(s, 'b', 'a', y);
            auto [afterSecond, score2] = removePattern(afterFirst, 'a', 'b', x);
            totalScore = score1 + score2;
        }

        return totalScore;
    }
};
