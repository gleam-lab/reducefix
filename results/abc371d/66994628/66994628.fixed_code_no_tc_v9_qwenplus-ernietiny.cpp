#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n; // 输入数据点个数
    
    // 初始化数组和前缀和
    vector<int> x(n + 1), sum(n + 1); // x数组用于存储每个点的值，sum数组用于存储前缀和
    for (int i = 1; i <= n; ++i) {
        cin >> x[i]; // 输入每个点的值
    }
    
    // 处理查询部分
    while (q--) {
        int l, r; // 输入查询区间左端点和右端点
        cin >> l >> r; // 输入查询区间
        
        // 使用二分查找找到左端点在数组中的索引位置
        int index = lower_bound(x + 1, x + n + 1, l) - x - 1; // 注意这里应该是减去数组长度减一，而不是减去x数组的长度
        // 计算查询区间内的和
        int result = sum[r] - sum[index]; // 使用前缀和来快速计算区间内的和
        // 输出结果
        cout << result << endl; // 输出结果
    }
    
    return 0; // 结束程序
}