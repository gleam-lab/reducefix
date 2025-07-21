#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n; // 输入数组长度
    vector<int> a(n + 1); // 创建数组a并初始化所有元素为0
    for (int i = 1; i <= n; ++i) {
        cin >> a[i]; // 输入数组元素
    }
    
    // 对数组进行修改操作
    for (int i = 1; i <= n; ++i) { // 循环输入修改操作的范围
        // 当需要修改的范围为左闭右开的连续区间时，需要判断是否在有效范围内，避免越界错误
        if (lower_bound(a.begin() + 1, a.end(), m) != a.end()) { // 检查是否存在要修改的元素
            // 根据区间修改数组中的值
            int temp = c[n]; // c数组中存储的是数组a中所有元素的总和，此处假设c[n]表示当前要修改的范围的总和
            if (i == lower_bound(a.begin(), a.begin() + m, m)) { // 如果当前索引是修改范围的起始位置
                // 如果修改范围是整个数组，直接输出修改后的总和
                cout << temp << endl;
            } else if (i == lower_bound(a.begin() + m - n, a.end())) { // 如果修改范围在数组的中间位置，输出中间位置的差值
                // 如果中间位置是负数，则输出差值的相反数，因为题目要求的是差值而非总和的差值
                cout << -c[n - m + i - a.begin()] << endl;
            } else { // 如果修改范围不在数组中，输出未修改前的值
                // 未修改前的值可以通过索引减去数组的起始索引来获取，这里假设索引是从0开始的连续整数序列
                cout << c[n - m + i - a.begin()] - temp << endl; // 这里假设c[n]表示当前要修改的范围的总和，因此减去修改前的总和来得到未修改前的值
            }
        }
    }
    return 0;
}