/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */

// @lc code=start
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UF uf(26);
        for (const auto& eq : equations) {
            if (eq[1] == '=') {
                uf._union(eq[0]-'a',eq[3]-'a');
            }
        }

        for (const auto& eq : equations) {
            if (eq[1] == '!') {
                if (uf.isConnected(eq[0]-'a',eq[3]-'a')) return false;
            }
        }

        return true;


    }

    class UF{
    vector<int> parent;
    public:
        UF(int n) {
            for(int i = 0; i < n; i++) {
                parent.push_back(i);
            }
        }
        int find(int x) {
        if(x!=parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void _union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX!=rootY) {
            parent[rootX] = rootY;
        }
    }

    bool isConnected(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        return rootX==rootY;
    }
    };
};
// @lc code=end

