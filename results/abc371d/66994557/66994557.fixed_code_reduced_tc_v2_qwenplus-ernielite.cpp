#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005];
long long sum[200005]; // 使用 long long 类型来处理可能的大数情况

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i]; // 正确的前缀和计算方式
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R; // 输入查询的左右边界
        // 使用lower_bound和upper_bound找到区间[L, R]在x数组中的位置
        auto l = lower_bound(x + 1, x + n + 1, L) - x; // 左边界位置，可能不是第一个完全在范围内的位置
        auto r = upper_bound(x + 1, x + n + 1, R) - x - 1; // 右边界位置，需要减一因为upper_bound会指向第一个大于R的位置
        // 检查边界情况，确保不会越界
        if (l > r) {
            cout << "0" << endl; // 如果左边界大于右边界，则区间为空，输出0
        } else {
            // 输出区间和，注意这里使用r而不是r-1（因为我们的数组是从1开始索引的）
            cout << sum[r] - sum[l - 1] << endl; // 注意这里l-1是正确的，因为我们要的是前缀和的差值
        }
    }
    return 0;
}