#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

// 其他的宏定义和变量初始化保持不变...

int main() {
    // ... 输入和初始化代码 ...

    // 确保 Q 的循环从 0 开始而不是 1（避免硬编码的特殊情况）
    rep(q, Q) {
        int L, R;
        cin >> L >> R; // 读取左右边界值
        // 使用 x_to_ptr 映射查找对应的索引范围
        auto X_l = x_to_ptr.lower_bound(L); // 找到第一个大于或等于 L 的键的迭代器
        auto X_r = x_to_ptr.upper_bound(R); // 找到第一个大于 R 的键的迭代器
        
        // 检查边界情况：如果 L 不在映射中，则 l 为 0（因为索引从 1 开始）
        // 如果 R 在映射中，则 r 为其索引减一（因为我们需要左边的索引）
        int l = (X_l == x_to_ptr.begin()) ? 0 : (X_l - 1)->second; // 注意减一因为我们是找左边界的索引
        int r = (X_r != x_to_ptr.end()) ? X_r->second : N; // 如果 R 不在映射中，则 r 为 N（边界情况）
        
        // 计算 P[r] 和 P[l] 的差值（确保不会出现负数）
        ll ans = (r > l ? P[r] - P[l] : 0); // 如果 r 大于 l，则计算差值；否则 ans 为 0 或负数时为正数（由于差值永远不会为负）
        cout << ans << endl; // 输出结果
    }
    // ... 其他代码 ...
}