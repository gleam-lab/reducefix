#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    vector<ll> p(n), s(n + 1, 0); // 初始化s数组为0
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (i > 0) s[i + 1] = s[i] + p[i]; // 确保s[i]是前i个p的累加和
    }
    s[0] = 0; // 添加一个哨兵值来避免当l=0时出现负索引的问题
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        // 注意这里的边界检查，避免r>n导致越界的情况发生
        if (r >= n) r = n - 1;
        // 寻找x中不小于l的最大值和不大于r的最小值的索引
        auto lt = lower_bound(x.begin(), x.end(), l);
        auto rt = upper_bound(x.begin(), x.end(), r);
        // 计算区间和时需要确保索引是有效的，并且考虑了哨兵值s[0] = 0的影响
        int ans = s[rt - x.begin()] - s[lt - x.begin() - 1]; // 注意这里要减去1来抵消哨兵值的影响
        cout << ans << endl;
    }
    return 0;
}