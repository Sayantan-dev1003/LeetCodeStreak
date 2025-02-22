/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<pair<TreeNode*, int>> stk;
        int i = 0, n = traversal.size();

        while (i < n) {
            int depth = 0;

            while (i < n && traversal[i] == '-') {
                depth++;
                i++;
            }

            int num = 0;
            while (i < n && isdigit(traversal[i])) {
                num = num * 10 + (traversal[i] - '0');
                i++;
            }

            TreeNode* node = new TreeNode(num);

            if (stk.empty()) {
                stk.push({node, depth});
                continue;
            }

            while (!stk.empty() && stk.top().second >= depth) {
                stk.pop();
            }

            if (!stk.empty()) {
                TreeNode* parent = stk.top().first;
                if (!parent->left) {
                    parent->left = node;
                } else {
                    parent->right = node;
                }
            }

            stk.push({node, depth});
        }

        while (stk.size() > 1) {
            stk.pop();
        }

        return stk.top().first;
    }
};
