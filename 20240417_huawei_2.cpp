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

#include<bits/stdc++.h>
using namespace std;


class UF{
public:
    int _n;
    vector<int> parent;
    UF(int n){
        _n= n;
        parent.resize(n);
        for(int i=0; i<n ; i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if (parent[x] != x) parent[x]= find(parent[x]);
        return parent[x];
    }

    void _union(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY) {
            parent[rootX] = rootY;
        }
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    int M;
    cin >> M;
    int N;
    cin >> N;
    int cnt = 0;
    UF uf(N);
    unordered_map<string,int> mp;
    vector<int> res(N, 0);
    int k = 0;
    for (int i = 0; i < N; i++) {
        string A;
        cin >> A;
        if (mp.find(A)== mp.end()) mp[A] = k++;

        string B;
        cin >> B;
        if( B!="*" && mp.find(B) == mp.end()) {
            mp[B] = k++;
          
        }
        if( B!="*") uf._union(mp[A], mp[B]);


        int C,D;
        cin >> C >> D;
        int p = uf.find(mp[A]);
        res[p] += ( C == 0 ? D*5 : D*2);
    } 


    for (const auto&node :res) {
        if(node != 0 && node > M) cnt++;
    }

    cout<<cnt<<endl;

    return 0;
 
}