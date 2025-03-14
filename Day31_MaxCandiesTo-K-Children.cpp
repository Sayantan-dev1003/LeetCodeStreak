class Solution {
public:
    bool canDistribute(const vector<int>& candies, long long k, long long mid) {
        long long count = 0;
        for (int candy : candies) {
            count += candy / mid;
            if (count >= k)
                return true;
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long totalCandies = accumulate(candies.begin(), candies.end(), 0LL);
        if (totalCandies < k)
            return 0;

        long long left = 1, right = *max_element(candies.begin(), candies.end());
        long long result = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canDistribute(candies, k, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};
