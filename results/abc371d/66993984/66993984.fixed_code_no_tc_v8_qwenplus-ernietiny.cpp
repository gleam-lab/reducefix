#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n; // 输入数据点个数
    
    // 初始化数组和映射
    vector<int> x(n), p(n);
    map<int, int> sum; // 假设sum是一个map，用于存储前缀和
    
    // 处理输入数据
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> p[i]; // 读入每个数据点的值和前缀和
        sum[p[i]]++; // 更新前缀和映射
    }
    
    // 处理查询操作
    while (q--) {
        int L, R; // 读入查询的两个数区间
        cin >> L >> R; // 读入查询的两个区间边界
        // 寻找区间内小于等于给定值的最大元素和大于给定值的最小元素的差值
        int c = lower_bound(x.begin(), x.end(), L) - x; // 下界为小于等于的边界，使用lower_bound获取索引
        int d = upper_bound(x.begin(), x.end(), R) - x; // 上界为大于的边界，使用upper_bound获取索引
        // 这里应直接返回sum[d-1] - sum[c]，避免额外的判断操作，保持代码简洁性
        cout << sum[d - 1] - sum[c] << endl; // 输出结果
    }
    return 0; // 结束程序
}