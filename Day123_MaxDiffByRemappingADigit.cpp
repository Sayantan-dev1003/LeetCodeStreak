class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int maxVal = INT_MIN;
        int minVal = INT_MAX;

        for (char from = '0'; from <= '9'; ++from) {
            for (char to = '0'; to <= '9'; ++to) {
                if (from == to)
                    continue;

                string temp = s;
                for (char& c : temp) {
                    if (c == from)
                        c = to;
                }

                int val = stoi(temp);
                maxVal = max(maxVal, val);
                minVal = min(minVal, val);
            }
        }

        return maxVal - minVal;
    }
};
