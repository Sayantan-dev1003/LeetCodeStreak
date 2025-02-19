class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for (int num : nums) {
            pq.push(num);
        }
        int ops = 0;
        while(pq.size() > 1 && pq.top() < k)
        {
            long long first = pq.top(); pq.pop();
            long long second = pq.top(); pq.pop();
            
            long long elem = first * 2 + second;
            ops += 1;
            pq.push(elem);
        }
        return ops;
    }
};
