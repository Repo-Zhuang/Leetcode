#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int poolMatrix(int N, const vector<vector<int>>& matrix) {
    function<int(int, int, int, int)> poolFunction = [&](int left, int top, int right, int bottom) -> int {
        int n = right - left + 1;
        // 如果当前区域只有一个元素，直接返回该元素的值
        if (n == 1) {
            return matrix[left][top];
        }
        // 否则，递归对四个子区域进行池化操作
        vector<int> subMatrix = {
            poolFunction(left, top, left + n / 2 - 1, top + n / 2 - 1),
            poolFunction(left, top + n / 2, left + n / 2 - 1, bottom),
            poolFunction(left + n / 2, top, right, top + n / 2 - 1),
            poolFunction(left + n / 2, top + n / 2, right, bottom)
        };
        // 对四个子区域的第二大元素进行排序，取第二大元素作为当前区域的第二大元素，并返回
        sort(subMatrix.begin(), subMatrix.end());
        return subMatrix[2];
    };

    // 调用池化函数，传入整个矩阵的范围进行池化操作，并返回结果
    return poolFunction(0, 0, N-1, N-1);
}

int main() {
    int N;
    cin >> N; // 读取矩阵的大小N
    vector<vector<int>> matrix(N, vector<int>(N)); // 创建矩阵

    // 读取矩阵的元素
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }

    // 调用池化函数，并输出最终结果
    int result = poolMatrix(N, matrix);
    cout << result << endl;

    return 0;
}