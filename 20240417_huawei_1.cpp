// 从一副扑克牌中随机抽取n张牌组成一个序列,规定连续3张相同牌号的卡牌可以消除,剩余卡牌按股当前顺序重新合并成新的片列后继续消除,
// 更复以上步骤直到无法消除,最后请输出结束后剩余的卡牌序列,
// 注:存在连续4张相同牌号的情况,消除后剩余一张。

// 输入:
// 第一行一个正整数n(1 <n< 52)，表示卡牌的数量。
// 第二行一个字符串,以空恪分隔代表卡牌号序列,卡牌号仅包含2-10,A, J, Q, K.
// 输出:
// 一个字符串,打印最终结束后的卡牌号序列,卡牌号以空格分隔。如果最终没有卡牌剩余输出0


#include<bits/stdc++.h>
#include <sstream>
using namespace std;

int main() {
    vector<string> card;

    int n;
    cin >> n;
    cin.ignore();

    string data;
    string res;
    getline(cin, data);
    istringstream ss(data);

    for (int i = 0; i < n; i++) {
        string temp;
        ss >> temp;

        if(i >= 2){
            if (temp == card[card.size() - 2]){
                card.pop_back();
                card.pop_back();
            }
            else {
                card.push_back(temp);
            }         
        }
        else{
            card.push_back(temp);
        }
    }

    for (auto& a : card) {
        res += a;
    }

    cout << res << endl;
    return 0;
}