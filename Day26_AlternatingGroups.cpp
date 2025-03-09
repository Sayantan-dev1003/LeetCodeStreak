class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        if (k > n) return 0;

        int count = 0, validCount = 0;

        for (int i = 0; i < k - 1; ++i) {
            if (colors[i] != colors[i + 1]) 
                validCount++;
        }
        
        if (validCount == k - 1) 
            count++;

        for (int i = 1; i < n; ++i) {
            int prevStart = (i - 1) % n;
            int newEnd = (i + k - 2) % n;
            int newStart = (i + k - 1) % n;

            if (colors[prevStart] != colors[(prevStart + 1) % n])
                validCount--;

            if (colors[newEnd] != colors[newStart])
                validCount++;

            if (validCount == k - 1)
                count++;
        }

        return count;
    }
};
