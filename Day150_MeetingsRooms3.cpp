class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<>> availableRooms;
        for (int i = 0; i < n; ++i) {
            availableRooms.push(i);
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> ongoing;

        vector<int> roomCount(n, 0);

        for (auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            while (!ongoing.empty() && ongoing.top().first <= start) {
                availableRooms.push(ongoing.top().second);
                ongoing.pop();
            }

            if (!availableRooms.empty()) {
                int room = availableRooms.top();
                availableRooms.pop();
                roomCount[room]++;
                ongoing.push({end, room});
            } else {
                auto [endTime, room] = ongoing.top();
                ongoing.pop();
                roomCount[room]++;
                ongoing.push({endTime + (end - start), room});
            }
        }

        int maxMeetings = 0, resultRoom = 0;
        for (int i = 0; i < n; ++i) {
            if (roomCount[i] > maxMeetings) {
                maxMeetings = roomCount[i];
                resultRoom = i;
            }
        }

        return resultRoom;
    }
};
