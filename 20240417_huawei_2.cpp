// 我们将云服务看做一棵树，每个云服务在发布前尚未解决的问题称为云服务的遗留问题(云服务的遗留问题包含以该云服务为根节点的树上所有节点的问题),
// DI值(遗留问题缺陷密度)可以作为评估云服务发布的指标,当云服务DI值小于等于阈值时才准许云服务发布,否则视为风,险云服务，需要问题整改完成后重新进行发布评估。
// 现有一批云服务树，已给出云服务树各节点的问题数量，请通过计算输出风险云服务的个数。
// 计算公式:DI值<5x严重问题数+2x一般问题数,
// 其中每个节点的不同级别问题数量需要将该节点及该节点为根节点的所有子节点的相应级别问题数量求和。

// 输入描述:
// 第一行输入M和N(M≤100000,N≤1000),使用空格分隔,M 表示代表云服务阈值， N 表示接下来有 N 行问题统计数据;
// 接下来输入一个 N*4 的矩阵表，行内使用空格分隔，
// 第一列 A_i为服务节点,
// 第二列 B_i为 A_i 的父节点，如果 Ai 为云服务则无父节点，此时 Bi 用*号表示( A_i和 B_i取值为字符串,1≤字符串长度 <5,均由小写萸文字母或 *号组成),
// 第三列C_i为问题级別(C_i取值为(0,1),0表示严重问题,1表示一般问题)
// 第四列 D_i为该节点该级别的问题数量(D_i< 1000)
// 说明:输入保证只出现树的关系，不会出现连通图的情况。

// 输出描述：
// 风险云服务的个数

// 样例1:
// 输入:
// 40 12
// a * 0 2
// a * 1 2
// b a 0 3
// b a 1 5
// c a 1 3
// d a 0 1
// d a 1 3
// e b 0 2
// f * 0 8
// f * 1 10
// g f 1 2
// h * 0 4
// 输出:
// 2

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

unordered_map<string, vector<string>> graph;
unordered_map<string, pair<int, int>> risks;
unordered_set<string> roots;

pair<int,int> dfs(const string& root) {
    int risk0 = risks[root].first;
    int risk1 = risks[root].second;

    for (const string& sub : graph[root])
    {
        auto risk = dfs(sub);
        risk0 += risk.first;
        risk1 += risk.second;
    }
    
    return {risk0, risk1};
}

int main() {
    int M, N;
    cin >> M >> N;
    cin.ignore();
    
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        string data;
        string A;
        string B;
        int C;
        int D;
        getline(cin, data);
        istringstream stream(data);
        stream >> A >> B >> C >> D; 

        if ( B == "*") {
            if (roots.find(A) == roots.end()){
                roots.insert(A);
                risks[A].first = 0;
                risks[A].second = 0;
            }
        }
        else {
            graph[B].push_back(A);
        }

        if(C == 0) {
            risks[A].first = D;
        }
        else {
            risks[A].second = D;
        }
    }

    for (const string& root : roots) {
        auto risks = dfs(root);
        if (5 * risks.first + 2 * risks.second > M) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
 
}