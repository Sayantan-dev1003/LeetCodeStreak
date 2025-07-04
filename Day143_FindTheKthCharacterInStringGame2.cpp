class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long length = 1;
        int totalOps = 0;

        while (length < k) {
            length *= 2;
            totalOps++;
        }

        k--;

        int characterShift = 0;

        for (int i = totalOps - 1; i >= 0; --i) {
            if (k >= length / 2) {
                if (operations[i] == 1) {
                    characterShift++;
                }
                k -= length / 2;
            }
            length /= 2;
        }

        return (characterShift % 26 + 'a');
    }
};
