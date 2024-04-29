/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */

// @lc code=start
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> eg(n+1);
        for(auto& E: eg) E.reserve(n+1);
        vector<int> vis(n+1, 0x3f3f3f3f);
         int ans = 0;
        for(auto& x: times){
            eg[x[0]].emplace_back(x[1], x[2]);
        }
    
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int ,int>>> q;


        q.emplace(0,k);
        while(!q.empty()) {
            auto [time, now] = q.top();
            q.pop();
            if(vis[now] < time) continue;
            ans = max(ans, time);
            vis[now] = time;
            for(auto [next, nextTime]: eg[now]){
                if(vis[next] > nextTime + time) {
                    q.emplace(nextTime + time, next);
                    vis[next] = nextTime + time;
                }
            }
        }
        return find(begin(vis)+1, end(vis), 0x3f3f3f3f) == end(vis) ? ans : -1;

    }
};
// @lc code=end

