class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        string maxS = s;
        for (char& c : maxS) {
            if (c != '9') {
                char target = c;
                for (char& ch : maxS) {
                    if (ch == target)
                        ch = '9';
                }
                break;
            }
        }

        string minS = s;
        if (s[0] != '1') {
            char target = s[0];
            for (char& ch : minS) {
                if (ch == target)
                    ch = '1';
            }
        } else {
            for (int i = 1; i < minS.size(); ++i) {
                if (minS[i] != '0' && minS[i] != '1') {
                    char target = minS[i];
                    for (char& ch : minS) {
                        if (ch == target)
                            ch = '0';
                    }
                    break;
                }
            }
        }

        int maxNum = stoi(maxS);
        int minNum = stoi(minS);
        return maxNum - minNum;
    }
};
