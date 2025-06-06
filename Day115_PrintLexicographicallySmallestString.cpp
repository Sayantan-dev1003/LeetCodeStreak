class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> minSuffix(n);
        minSuffix[n - 1] = s[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            minSuffix[i] = min(s[i], minSuffix[i + 1]);
        }

        stack<char> t;
        string result;
        int i = 0;

        while (i < n || !t.empty()) {
            if (!t.empty() && (i == n || t.top() <= minSuffix[i])) {
                result += t.top();
                t.pop();
            } else {
                t.push(s[i]);
                i++;
            }
        }

        return result;
    }
};
