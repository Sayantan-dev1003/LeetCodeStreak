class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int>indegree;
        unordered_map<string, vector<string>>graph;
        unordered_set<string> available(supplies.begin(), supplies.end());
        queue<string> q;
        vector<string> result;

        for (int i = 0; i < recipes.size(); ++i) {
            indegree[recipes[i]] = ingredients[i].size();
            for (const string& ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]);
            }
        }

        for (const string& s : supplies) {
            q.push(s);
        }

        while (!q.empty()) {
            string item = q.front();
            q.pop();

            if (indegree.find(item) != indegree.end()) {
                result.push_back(item);
            }

            for (const string& recipe : graph[item]) {
                if (--indegree[recipe] == 0) {
                    q.push(recipe);
                }
            }
        }

        return result;
    }
};
