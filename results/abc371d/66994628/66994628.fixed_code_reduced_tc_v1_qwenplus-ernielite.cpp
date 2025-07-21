#include<bits/stdc++.h>
using namespace std;

int n, q, x[200005], p[200005], sum[200005]; // 修改sum的声明以匹配实际使用

int main() {
    cin >> n;
    // 初始化sum数组为0
    for (int i = 0; i <= n; i++) {
        sum[i] = 0; // 确保sum数组初始化为0
    }
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    // 计算前缀和（从第1个元素开始）
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i]; // 注意这里是累加到当前元素上
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r; // 读取查询的左右边界值
        // 使用lower_bound和upper_bound来找到对应的索引（注意处理重复值的情况）
        auto it_l = lower_bound(x + 1, x + n + 1, l); // 找到第一个大于等于l的元素的位置
        auto it_r = upper_bound(x + 1, x + n + 1, r) - 1; // 找到第一个大于r的元素的位置（注意减一）
        l = it_l - x; // 计算在x数组中的实际索引（减去偏移量）
        r = it_r - x; // 计算在x数组中的实际索引（同样需要减去偏移量）
        // 现在可以安全地使用l和r来计算前缀和的差值了
        cout << sum[r] - sum[l - 1] << endl; // 注意这里要减去1来避免越界（因为数组是从1开始的）
    }
}