class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd_count = 0, even_count = 1;
        int prefix_sum = 0, counter = 0;
        int MOD = 1e9 + 7;
        
        for (int num : arr) {
            prefix_sum += num;
            
            if (prefix_sum % 2 != 0) {
                counter = (counter + even_count) % MOD;
                odd_count++; 
            } else {
                counter = (counter + odd_count) % MOD;
                even_count++;
            }
        }
        
        return counter;
    }
};
