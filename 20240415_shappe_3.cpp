// 给定一个int数组nums,排列每个数的顺序(每个数不可拆分,比如12不能拆成1和2)，使之组成一个最大的整数。注意:输出结果可能非常大，所以返回一个字符串而不是整数。
// 示例1
// 输入
// [10,2]
// 输出
// "210"struct LargerNumberComparator {
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


string solution(vector<int>& nums) {
    vector<string> temp;
    string result;
    for (int a : nums){
       temp.push_back(to_string(a));
    }

    
    sort(temp.begin(), temp.end(),[](string a, string b) -> bool{
       return  a+b > b+a;
    });    
    
    for (auto s : temp) {
        result += s;
    }

    if (!result.empty() && result[0] == '0') return "0";
    return result;

}
int main() {
    vector<int> nums ={10,2,3,4,5};
    cout << solution(nums) <<endl;

    return 0;
}