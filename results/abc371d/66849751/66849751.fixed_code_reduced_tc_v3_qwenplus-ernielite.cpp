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
        auto X_l_it = x_to_ptr.lower_bound(L);
        auto X_r_it = x_to_ptr.upper_bound(R);
        
        // 如果L大于当前X数组中的最大值，则l设为N
        if (X_l_it == x_to_ptr.end()) {
            int l = N; // 确保l是一个int类型的值
        } else {
            // 获取当前迭代器的索引值
            int l = X_l_it->second;
        }
        // 如果R小于X数组中的最小值或等于X[0]，则r设为0（或1，取决于题意）
        if (X_r_it == x_to_ptr.begin()) {
            int r = 0; // 假设题目中最小索引为1开始，这里设为0；如果是从1开始则不需要调整
        } else {
            // 向后遍历一个单位获取上一个元素的索引（因为upper_bound会指向超出范围的下一个位置）
            --X_r_it; 
            int r = X_r_it->second; // 获取当前迭代器的索引值
        }
        
        // 计算差值并输出
        int ans = P[r] - P[l]; // 确保l和r是有效的索引（不会越界）
        cout << ans << endl;
    }
    // ... 其他部分保持不变 ...
}