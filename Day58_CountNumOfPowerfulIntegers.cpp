class Solution {
private:
    long long countChakraShinobi(long long val, int limit, const string& clanSymbol) {
        string chakraFlow = to_string(val);
        int prefixLength = chakraFlow.length() - clanSymbol.length();

        if (prefixLength < 0)
            return 0;

        vector<vector<long long>> rasenganScroll(prefixLength + 1, vector<long long>(2, 0));

        rasenganScroll[prefixLength][0] = 1;
        rasenganScroll[prefixLength][1] =
            chakraFlow.substr(prefixLength) >= clanSymbol ? 1 : 0;

        for (int i = prefixLength - 1; i >= 0; --i) {
            int currentChakra = chakraFlow[i] - '0';

            rasenganScroll[i][0] = (limit + 1) * rasenganScroll[i + 1][0];

            if (currentChakra <= limit) {
                rasenganScroll[i][1] =
                    (long long)currentChakra * rasenganScroll[i + 1][0] + rasenganScroll[i + 1][1];
            } else {
                rasenganScroll[i][1] = (long long)(limit + 1) * rasenganScroll[i + 1][0];
            }
        }

        return rasenganScroll[0][1];
    }

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return countChakraShinobi(finish, limit, s) - countChakraShinobi(start - 1, limit, s);
    }
};
