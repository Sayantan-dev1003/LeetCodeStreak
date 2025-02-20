class Solution {
    bool generateAllBinary(string s, vector<string>& nums, int n, string& result) {
        if (s.length() == n) {
            if (find(nums.begin(), nums.end(), s) == nums.end()) {
                result = s; 
                return true;
            }
            return false;
        }
        if (generateAllBinary(s + "0", nums, n, result)) return true;
        if (generateAllBinary(s + "1", nums, n, result)) return true;
        return false;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string result = "";
        generateAllBinary("", nums, nums.size(), result);
        return result;
    }
};
