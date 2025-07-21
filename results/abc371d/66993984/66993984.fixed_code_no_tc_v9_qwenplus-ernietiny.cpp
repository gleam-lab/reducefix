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
        cin >> x[i] >> p[i]; // 读取每个数据点的值
        sum[i] = sum[i - 1] + p[i]; // 更新前缀和
    }
    
    // 处理查询部分
    while (q--) { // 处理q个查询
        int L, R; // 输入区间左右端点
        cin >> L >> R; // 读取查询区间左右端点
        // 获取区间的差值前缀和差值
        int c = lower_bound(x.begin(), x.end(), L) - x.begin(); // 上界索引减去当前数组索引，可能需要根据具体情况调整索引范围
        int d = upper_bound(p.begin(), p.end(), R) - p.begin(); // 下界索引减去当前数据点数组索引，可能需要根据具体情况调整索引范围
        // 计算差值前缀和差值结果输出
        cout << sum[d - 1] - sum[c - 1] << endl; // 这里假设sum是一个map，可以直接使用差值计算结果输出
    }
    
    return 0; // 返回0表示程序正常结束
}