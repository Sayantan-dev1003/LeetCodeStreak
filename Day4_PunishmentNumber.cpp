class Solution {
    bool canPartition(string numStr, int target, int index = 0, int currentSum = 0) {
        if (index == numStr.length()) {
            return currentSum == target;
        }

        int value = 0;
        for (int j = index; j < numStr.length(); j++) {
            value = value * 10 + (numStr[j] - '0');
            if (currentSum + value > target)
                break;
            if (canPartition(numStr, target, j + 1, currentSum + value))
                return true;
        }

        return false;
    }

public:
    int punishmentNumber(int n) {
        int totalSum = 0;
        for (int i = 1; i <= n; i++) {
            int square = i * i;
            string squareStr = to_string(square);
            if (canPartition(squareStr, i)) {
                totalSum += square; // Add valid i^2 to sum
            }
        }
        return totalSum;
    }
};
