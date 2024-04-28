// 要实现指定字符串中每个单词字符顺序反转的功能，同时保持单词的初始顺序和空格位置不变，你可以按照以下步骤编写代码：

// 分割字符串，使用空格作为分隔符来获得单词列表。
// 对列表中的每个单词

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string reverseString(string str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        // 交换首尾字符
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
    return str;
    string result;
}

int main() {
    string data;
    getline(cin, data);
    istringstream stream(data);
    string word;
    string res;
    while(stream >> word) {
        word = reverseString(word);
        if (!res.empty()) {
            res+= ' ';
        }
        res+=word;
    }
    cout << res <<endl;

}