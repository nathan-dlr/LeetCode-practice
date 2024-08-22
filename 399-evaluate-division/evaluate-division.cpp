class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        unordered_map<string, unordered_map<string, double>> graph;
        string var1, var2;
        for (int i = 0; i < equations.size(); i++) {
            var1 = equations[i][0];
            var2 = equations[i][1];
            graph[var1][var2] = values[i];
            graph[var2][var1] = 1 / values[i];
        }
        for (int i = 0; i < queries.size(); i++) {
            var1 = queries[i][0];
            var2 = queries[i][1];
            if (graph.find(var1) == graph.end() || graph.find(var2) == graph.end()) {
                ans.push_back(-1);
            }
            else {
                unordered_set<string> visited;
                double quotient = -1, temp = 1;
                EvaluateDivision(var1, var2, visited, graph, quotient, temp);
                ans.push_back(quotient);

            }

        }
        return ans;
    }
    void EvaluateDivision(string var1, string var2, unordered_set<string> visited,  unordered_map<string, unordered_map<string, double>> &graph, double &quotient,double temp) {
        if (visited.find(var1) != visited.end()) {
            return;
        }
        visited.insert(var1);
        if (var1 == var2) { 
            quotient = temp;
            return;
        }

        for(auto neighbor : graph[var1]) {
            EvaluateDivision(neighbor.first, var2, visited, graph, quotient, temp * neighbor.second);
        }
        return;
    }
};