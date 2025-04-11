class Solution {
private:
    bool isSymmetric(int num) {
        string s = to_string(num);
        int n = s.length();
        if (n % 2 != 0)
            return false;

        int half = n / 2;
        int sum_first = 0, sum_second = 0;

        for (int i = 0; i < half; ++i) {
            sum_first += s[i] - '0';
            sum_second += s[n - 1 - i] - '0';
        }

        return sum_first == sum_second;
    }

public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int num = low; num <= high; ++num) {
            if (isSymmetric(num)) {
                ++count;
            }
        }
        return count;
    }
};
