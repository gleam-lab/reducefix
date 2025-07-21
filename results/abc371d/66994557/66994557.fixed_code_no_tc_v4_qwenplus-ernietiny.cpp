#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n; // 输入数据点个数
    
    // 初始化数组和前缀和
    vector<int> x(n + 1), p(n + 1); // x[i]存储第i个数据点的值，p[i]存储前缀和
    for (int i = 1; i <= n; ++i) {
        cin >> x[i]; // 输入每个数据点的值
    }
    for (int i = 1; i <= n; ++i) {
        p[i] = x[i]; // 前缀和初始化
    }
    
    // 处理查询部分
    cin >> q; // 输入查询次数
    while (q--) {
        int L, R; // 输入左端点和右端点
        cin >> L >> R; // 输入查询区间
        // 检查边界条件，确保查询有效
        if (L < 1 || R > n || L > R + 1) {
            // 处理错误情况，例如超出范围等
            cerr << "Invalid query range" << endl;
            continue; // 跳过错误处理并继续处理下一个查询
        }
        // 使用二分查找找到右端点对应的区间和值
        int l = lower_bound(x + 1, x + n + 1, L) - x - 1; // 使用二分查找找到左端点对应的区间下标
        int sum = p[R] - p[l]; // 根据前缀和计算区间和值
        // 输出结果，这里应该输出查询区间内的和值，而不是直接输出sum[r-1]-sum[l-1]
        cout << sum << endl; // 注意这里应该输出的是区间内的和值，而不是区间和本身
    }
    return 0; // 返回0表示程序正常结束
}