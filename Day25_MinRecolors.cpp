class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int minOps = k;
        int currentWhite = 0;

        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                currentWhite++;
            }
        }
        minOps = currentWhite;

        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i - k] == 'W') {
                currentWhite--;
            }
            if (blocks[i] == 'W') {
                currentWhite++;
            }
            minOps = min(minOps, currentWhite);
        }

        return minOps;
    }
};
