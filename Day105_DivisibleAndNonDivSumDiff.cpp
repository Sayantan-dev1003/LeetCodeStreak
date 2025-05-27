class Solution {
public:
    int differenceOfSums(int n, int m) {
        int totalSum = n * (n + 1) / 2;

        int countDivByM = n / m;

        int sumDivByM = m * countDivByM * (countDivByM + 1) / 2;

        return totalSum - 2 * sumDivByM;
    }
};
