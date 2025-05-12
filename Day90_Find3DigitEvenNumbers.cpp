class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        array<int, 10> freq = {0};
        int cntEven = 0;
        for (int x : digits) {
            freq[x]++;
            cntEven += (x & 1) == 0;
        }
        if (cntEven == 0)
            return {};
        vector<int> ans;
        for (int x = 1; x <= 9; x++) {
            if (freq[x] <= 0)
                continue;
            freq[x]--;
            for (int y = 0; y <= 9; y++) {
                if (freq[y] <= 0)
                    continue;
                freq[y]--;
                for (int z = 0; z < 9; z += 2) {
                    if (freq[z] <= 0)
                        continue;
                    ans.push_back(100 * x + 10 * y + z);
                }
                freq[y]++;
            }
            freq[x]++;
        }
        return ans;
    }
};
