#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n+1), c(n+1); // 不再需要 b 数组，因为它未被使用
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        c[i] = c[i - 1] + a[i]; // 计算前缀和
    }
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        // 在 a 中找到第一个大于等于 l 的位置和第一个大于 r 的位置的前一个位置
        auto l_i = lower_bound(a.begin() + 1, a.end(), l);
        auto r_j = upper_bound(a.begin() + 1, a.end(), r) - 1; // 减一以找到前一个大于 r 的位置
        // 如果 l 不在 a 中，则直接跳过；如果 r 不在 a 中则将 j 设为 a 的最后一个位置（即 n）
        int i = (l_i == a.begin() || *l_i != l) ? 0 : (l_i - a.begin());
        int j = (r_j == a.end() || *r_j != r) ? n : (r_j - a.begin());
        // 计算介于 l 和 r 的元素个数（包括 l 和 r）
        if (l <= a[n] && r >= a[1]) { // 确保 l 和 r 在数组范围内
            cout << c[j] - c[i] << endl; // 输出前缀和的差值，即元素个数
        } else {
            // 如果 l 或 r 超出了数组范围，则输出错误信息或处理边界情况（根据实际需求）
            cout << "Error: l or r out of bounds" << endl;
        }
    }
    return 0;
}