class Solution {
    void generateHappyStrings(int n, string& s, vector<string>& happyStrings, char lastChar) {
        if (s.length() == n) {
            happyStrings.push_back(s);
            return;
        }

        for (char ch : {'a', 'b', 'c'}) {
            if (ch != lastChar) {
                s.push_back(ch);
                generateHappyStrings(n, s, happyStrings, ch);
                s.pop_back(); 
            }
        }
    }

public:
    string getHappyString(int n, int k) {
        vector<string> happyStrings;
        string s;
        generateHappyStrings(n, s, happyStrings, '\0'); 

        if (k > happyStrings.size())
            return "";

        return happyStrings[k - 1]; 
    }
};
