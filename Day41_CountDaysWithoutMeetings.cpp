class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty())
            return days;

        sort(meetings.begin(), meetings.end());

        int busyDays = 0;
        int mergedStart = meetings[0][0], mergedEnd = meetings[0][1];

        for (int i = 1; i < meetings.size(); i++) {
            int start = meetings[i][0], end = meetings[i][1];

            if (start <= mergedEnd + 1) {
                mergedEnd = max(mergedEnd, end);
            } else {
                busyDays += (mergedEnd - mergedStart + 1);
                mergedStart = start;
                mergedEnd = end;
            }
        }
        busyDays += (mergedEnd - mergedStart + 1);

        return days - busyDays;
    }
};
