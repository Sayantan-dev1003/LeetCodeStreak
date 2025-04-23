class Solution {
public:
    int sumOfDigits(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int> digitSumCount;
        int maxSize = 0;

        for (int i = 1; i <= n; ++i) {
            int sum = sumOfDigits(i);
            digitSumCount[sum]++;
            maxSize = max(maxSize, digitSumCount[sum]);
        }

        int result = 0;
        for (const auto& pair : digitSumCount) {
            if (pair.second == maxSize) {
                result++;
            }
        }

        return result;
    }
};
