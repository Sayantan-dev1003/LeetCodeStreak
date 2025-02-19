// class Solution {
//     int digitSum(int n) {
//         int sum = 0;
//         while (n > 0) {
//             sum += n % 10;
//             n /= 10;
//         }
//         return sum;
//     }

// public:
//     int maximumSum(vector<int>& nums) {
//         unordered_map<int, int> hashTable;

//         sort(nums.begin(), nums.end());
//         vector<int> arr = {};
//         int temp = -1;

//         for (int i = 0; i < nums.size(); i++) {
//             hashTable[nums[i]] = digitSum(nums[i]);
//             if (temp == nums[i]) arr.push_back(nums[i]);
//             else temp = nums[i];
//         }
//         int mx = 0;
//         for (auto key1 : hashTable) {
//             for (auto key2 : hashTable) {
//                 if (key1.second == key2.second && key1.first != key2.first) {
//                     int temp = key1.first + key2.first;
//                     mx = max(temp,mx);
//                 }
//             }
//         }
//         for (int i = 0; i < arr.size(); i++) {
//             mx = max(mx, 2*arr[i]);
//         }
//         if (mx == 0)
//             return -1;
//         else
//             return mx;
//     }
// };
class Solution {
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> hashTable; 
        int maxSum = -1;

        for (int num : nums) {
            int sumDigits = digitSum(num);

            if (hashTable.count(sumDigits)) {
                maxSum = max(maxSum, hashTable[sumDigits] + num);
            }

            hashTable[sumDigits] = max(hashTable[sumDigits], num);
        }

        return maxSum;
    }
};
