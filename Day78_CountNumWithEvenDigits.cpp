class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int num : nums) {
            int digit = 0;
            int temp = num;
            while (temp != 0) {
                temp /= 10;
                digit++;
            }
            if (digit % 2 == 0)
                count++;
        }
        return count;
    }
};
