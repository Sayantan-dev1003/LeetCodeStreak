class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;

        for (const string& f : folder) {
            if (result.empty() ||
                f.substr(0, result.back().size()) != result.back() ||
                f[result.back().size()] != '/') {
                result.push_back(f);
            }
        }

        return result;
    }
};
