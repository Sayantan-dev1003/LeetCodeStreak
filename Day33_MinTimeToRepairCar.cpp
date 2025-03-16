class Solution {
public:
    bool canRepairInTime(const vector<int>& ranks, int cars, long long time) {
        int totalCars = 0;
        for (int r : ranks) {
            int n = 0;
            while ((long long)r * (n + 1) * (n + 1) <= time) {
                n++;
            }
            totalCars += n;
            if (totalCars >= cars)
                return true;
        }
        return totalCars >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1, right = (long long)*min_element(ranks.begin(), ranks.end()) * cars * cars;
        long long ans = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canRepairInTime(ranks, cars, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
