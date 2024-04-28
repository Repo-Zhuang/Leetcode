// 英雄联盟游戏中新出n个英雄,用长度为n的数组 costs 表示每个英雄的定价，其中 costs[i]表示第i个英雄的点券价格。假如你一共有coins 点券可以用于消费,
// 且想要买尽可能多的英雄并日选择英雄按costs[]给出顺序获取给你价格数组 costs 和金币量 coins ，请你计算并返回用 coins 金币能够买到最多的英雄列表
#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

using namespace std;

vector<int> maxHeroes(vector<int>& costs, int coins) {
    vector<pair<int,int>> temp;
    for (int i = 0; i < costs.size(); i++) {
        temp.push_back({costs[i],i});
    }
    sort(temp.begin(), temp.end()); // 对价格数组进行排序
    vector<int> result; // 用来存放可以购买的英雄的索引
    int totalCost = 0; // 已经花费的金币总数

    for (int i = 0; i < temp.size(); ++i) {
        if (totalCost + temp[i].first <= coins) { // 检查是否有足够的金币购买当前英雄
            totalCost += temp[i].first; // 更新已花费的金币数
            result.push_back(temp[i].second); // 将此英雄的原始索引添加到结果列表中
        } else {
            break; // 如果金币不够购买当前英雄，结束循环
        }
    }
    
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); ++i) { 
        result[i]=costs[result[i]];
    }
    
    return result; // 返回可以购买的英雄的列表
}

int main() {
    vector<int> costs = {10,1, 2, 3, 4, 5}; // 英雄的定价列表
    int coins = 10; // 可用的点券数量

    vector<int> purchasedHeroes = maxHeroes(costs, coins);

    cout << "Indices of heroes you can buy: ";
    for (int index : purchasedHeroes) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}