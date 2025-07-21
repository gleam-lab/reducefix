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
    
    // 处理输入数据，更新c数组并查找特定区间内的元素值
    for (int i = 1; i <= n; ++i) {
        c[i] = a[i] + c[i - 1]; // c[i]更新为前一个元素加当前元素的和
    }
    
    while (m--) { // 处理m个查询区间
        int l, r; // 输入查询区间的左端点和右端点
        cin >> l >> r; // 输入查询区间左端点和右端点
        // 使用二分查找找到符合条件的区间内的元素值
        auto l_i = lower_bound(a.begin() + 1, a.end(), l); // 二分查找左边界
        auto r_i = upper_bound(a.begin(), a.end(), r); // 二分查找右边界
        if (r_i == a.end()) { // 如果右边界不存在于数组中，直接输出c[n]
            cout << c[n] << endl; // 直接输出c[n]表示整个数组的值
        } else if (r_i == a.begin()) { // 如果查询区间起始于数组的开始位置，直接输出当前元素的值
            cout << c[n] << endl; // 直接输出当前元素的值，等同于数组a中从起始位置到查询区间的所有元素和
        } else { // 其他情况，通过区间差值进行计算并输出结果
            cout << (c[r_i] - c[l_i - a.begin() - 1]) << endl; // 通过区间差值计算并输出结果
        }
    }
    return 0;
}