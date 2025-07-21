#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n+1), b(n+1), c(n+1, 0); // 修正c初始化为0的初始化方式
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        c[i] = c[i - 1] + a[i]; // 修正计算前缀和的方式，c[i]为c[i-1]与a[i]的和
    }
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        auto l_i = lower_bound(a.begin() + 1, a.end(), l); // 找到第一个大于等于l的元素位置
        auto r_j = upper_bound(a.begin() + 1, a.end(), r); // 找到第一个大于r的元素位置
        int i = l_i - a.begin(); // 计算l在a中的索引（注意这里要减去偏移量）
        int j = (r_j == a.end()) ? n : r_j - a.begin(); // 如果r超出了a的范围，则j为n（数组末尾）
        if (l > 0) { // 如果l不等于0，即存在需要计算的区间
            if (r >= a[n]) { // 如果r大于数组的最后一个元素，则使用整个数组的末尾值来计算
                cout << c[n] << endl; // 直接输出c[n]，因为c[n]已经包含了从c[i-1]到c[n]的和
            } else { // 否则，计算区间和并输出结果
                cout << c[j] - c[i-1] << endl; // 输出c[j]减去c[i-1]，即从a中第i个到第j个元素的和
            }
        }
    }
    return 0;
}