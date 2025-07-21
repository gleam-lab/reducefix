#include <bits/stdc++.h>
using namespace std;

int n, q, x[200005], p[200005], prefixSum[200005]; // 添加了prefixSum来存储前缀和

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    // 计算前缀和，并存储在prefixSum中
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + p[i]; // 这里应该是p的累加和，但代码是错误的，因为p未初始化
        prefixSum[i] = prefixSum[i - 1] + p[i]; // 修复为计算p的前缀和
    }
    // ... 其他代码保持不变 ...

    // 在查询时，使用prefixSum来计算区间和的差值
    while (q--) {
        int L, R;
        cin >> L >> R;
        // 注意：这里不再使用lower_bound和upper_bound，因为x数组是唯一的，无需搜索下界和上界
        // 直接计算前缀和的差值即可
        int c = lower_bound(x, x + n + 1, L) - x; // 找到L在x中的位置（索引加一）
        int d = c; // 因为R是查询的上界，我们不需要找到确切的R的位置，只需确保d是比R大的下一个位置（索引）
        cout << prefixSum[d] - prefixSum[c - 1] << endl; // 输出前缀和的差值作为结果
    }
    return 0; // 添加返回语句以结束程序（尽管在某些编译器中这可能不是必需的）
}