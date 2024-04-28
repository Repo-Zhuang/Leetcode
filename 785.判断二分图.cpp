/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
class Solution {
private:
    vector<int> color;
    bool valid = true;

public:
    void dfs(int node, int c, const vector<vector<int>>& graph) {
        color[node] = c;
        int cNei = (c == 1 ? 2 : 1);
        for (int neighbor: graph[node]) {
            if (color[neighbor] == 0) {
                dfs(neighbor, cNei, graph);
                if (!valid) {
                    return;
                }
            }
            else if (color[neighbor] != cNei) {
                valid = false;
                return;
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color.resize(n,0);
          for (int i = 0; i < n && valid; ++i) {
            if (!color[i]) {
                dfs(i, 1, graph);
            }
        }
        return valid;
    }

};
// @lc code=end

 