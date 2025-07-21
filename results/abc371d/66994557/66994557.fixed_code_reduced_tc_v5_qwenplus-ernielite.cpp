#include<bits/stdc++.h>
using namespace std;

// 定义数组大小要足够大以容纳所有可能的索引
const int MAXN = 200005;
int n, q, x[MAXN], p[MAXN], sum[MAXN];

int main() {
    cin >> n;
    // 读取x和p的值，并同时计算前缀和sum
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> p[i];
        sum[i] = sum[i - 1] + p[i]; // 更新前缀和
    }

    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        // 使用lower_bound和upper_bound找到x中第一个大于等于L和小于R的索引，然后利用这两个索引在sum中查询结果
        // 修改lower_bound和upper_bound的起始地址为sum的前一个元素的地址（注意，前缀和数组sum从1开始，所以我们需要从sum-1的地址开始）
        auto l = lower_bound(x + 1, x + n + 1, L) - x;
        auto r = upper_bound(x + 1, x + n + 1, R) - x;
        // 由于lower_bound和upper_bound返回的是指向元素的指针，所以需要减去1来获取数组的索引（即前缀和数组的索引）
        l--; r--; // 如果找不到任何元素则l或r可能超出范围，需特别注意
        if (l < 0) l = 0; // l超出了数组边界时应该处理为0（或者更接近的合法值）
        if (r > n) r = n; // r超出了数组边界时应该处理为n（或使用前缀和数组的最大索引）
        // 输出查询结果（使用sum的相应前缀和来计算差值）
        cout << sum[r] - sum[l] << endl; // 注意：当r为n时应该计算至sum[n-1]，防止数组越界错误
    }
    return 0;
}