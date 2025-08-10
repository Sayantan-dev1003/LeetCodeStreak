class Solution {
public:
    string sortedDigits(int x) {
        string s = to_string(x);
        sort(s.begin(), s.end());
        return s;
    }
    bool reorderedPowerOf2(int n) {
        string target = sortedDigits(n);

        for (int i = 0; i < 31; i++) {
            if (sortedDigits(1 << i) == target)
                return true;
        }
        return false;
    }
};
