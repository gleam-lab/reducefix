#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

// ... 其他定义保持不变 ...

int main() {
    // ... 输入部分保持不变 ...

    // 修改查询部分以正确获取l和r的值
    rep(q, Q) {
        int L, R;
        cin >> L >> R;
        // 使用二分查找确定L和R的索引
        auto X_l = lower_bound(all(x_to_ptr), L);
        auto X_r = upper_bound(all(x_to_ptr), R);
        // 检查X_l和X_r是否有效（即它们是否真的在map中）
        int l = (X_l != x_to_ptr.end()) ? X_l->second : N; // 如果找不到L，则使用N作为索引
        int r = (X_r != x_to_ptr.begin()) ? prev(X_r)->second : 0; // 如果R超出了范围或为最小值，则使用0作为索引（或根据实际情况调整）
        // 确保l <= r，否则如果R超出了范围，l仍为N时，r会是一个无效的索引
        if (l > r) { // 这种情况应该根据实际情况处理，这里假设R超出了范围则r设为0是合理的
            swap(l, r); // 或者根据实际需求决定如何处理这种情况
        }
        // 计算并输出结果，注意这里要确保P数组有足够的元素覆盖到l和r的索引+1
        int ans = (r > 0) ? P[r] - P[l] : 0; // 如果r为0或无效索引，则不进行计算或返回0（根据实际情况调整）
        cout << ans << endl;
    }
}