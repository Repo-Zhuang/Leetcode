/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        traverse(graph, 0, path);
        return res;
    }
    void traverse(vector<vector<int>>& graph, int s, vector<int>& path) {

        // 添加节点 s 到路径
        path.push_back(s);

        int n = graph.size();
        if (s == n - 1) {
            // 到达终点
            res.push_back(path);
            // 可以在这直接 return，但要正确维护 path
            // path.pop_back();
            // return;
            // 不 return 也可以，因为图中不包含环，不会出现无限递归
        }

        // 递归每个相邻节点
        for (int v : graph[s]) {
            traverse(graph, v, path);
        }
        
        // 从路径移出节点 s
        path.pop_back();
    }

};
// @lc code=end

