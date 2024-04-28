/*
 * @lc app=leetcode.cn id=886 lang=cpp
 *
 * [886] 可能的二分法
 */

// @lc code=start
class Solution {
private:

vector<int> color;
vector<vector<int>> graph;
bool valid = true;
public:
    void dfs(int u, int c) {
        color[u] = c;
        int cur = (c == 1? 2 : 1);
        for (int v: graph[u]){
            if (color[v] == 0) {
                dfs(v, cur);
                if(!valid) return;
            }
            if (color[v] != cur) {
                valid =false;
                return ;
            }
        }
        
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        color.resize(n + 1, 0);
        graph.resize(n + 1);

        for (const auto& info : dislikes) {
            graph[info[0]].push_back(info[1]);
            graph[info[1]].push_back(info[0]);
        }

        for(int i = 1 ; i < n + 1 && valid; i++) {
            if (!color[i]){
                dfs(i, 1);
            }
        }
        return valid;
    }
};

// @lc code=end

