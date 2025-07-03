class Solution {
public:
    char kthCharacter(int k) {
        long long current_length = 1;
        while (current_length < k) {
            current_length *= 2;
        }

        int total_shifts = 0;
        int current_k = k;

        while (current_length > 1) {
            current_length /= 2;

            if (current_k > current_length) {
                current_k -= current_length;
                total_shifts++;
            }
        }

        return (char)('a' + (total_shifts % 26));
    }
};
