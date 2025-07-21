#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n; // 输入数据点个数
    vector<int> a(n + 1); // 初始化数组a
    for (int i = 1; i <= n; ++i) { // 输入每个数据点的值
        cin >> a[i];
    }
    
    // 处理数据，避免越界访问数组元素
    for (int i = 1; i <= n; ++i) { // 初始化c数组，并填充数据
        c[i] = a[i] + c[i - 1]; // 这里应该是累加而不是赋值给c[i]
    }
    
    // 分析题目要求并修正代码
    while (m--) { // 处理每个测试用例
        int l, r; // 输入两个数据点作为区间边界
        cin >> l >> r; // 读入区间边界
        // 使用lower_bound和upper_bound查找区间内的元素位置
        int i = lower_bound(a.begin() + 1, a.end(), l) - a.begin(); // 计算区间左端点索引
        int j = upper_bound(a.begin() + 1, a.end(), r) - a.begin(); // 计算区间右端点索引
        // 根据题目要求进行计算并输出结果
        if (r >= a[n]) { // 如果右端点大于等于最后一个数据点，输出差值
            cout << c[n] - c[i - 1] << endl; // 这里应该是减去c[n]，而不是c[i-1]
        } else { // 如果右端点小于最后一个数据点，输出差值减去前一个数据点的值
            cout << c[j - 1] - c[i - 1] << endl; // 这里应该修正为差值减去前一个数据点的值加上当前数据点的值
        }
    }
    return 0; // 返回0表示程序正常结束
}