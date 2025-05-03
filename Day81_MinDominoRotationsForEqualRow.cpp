class Solution {
private:
    int check(int target, vector<int>& tops, vector<int>& bottoms) {
        int rotateTop = 0, rotateBottom = 0;
        for (int i = 0; i < tops.size(); ++i) {
            if (tops[i] != target && bottoms[i] != target)
                return -1;
            else if (tops[i] != target)
                ++rotateTop;
            else if (bottoms[i] != target)
                ++rotateBottom;
        }
        return min(rotateTop, rotateBottom);
    }

public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int rotations = check(tops[0], tops, bottoms);
        if (rotations != -1 || tops[0] == bottoms[0])
            return rotations;
        else
            return check(bottoms[0], tops, bottoms);
    }
};
