#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n+1), b(n+1), c(n+1, 0); // 修改了变量类型为int，并移除了不必要的初始化
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i]; // 假设b是a的副本，这里只是用于演示，具体根据题目要求来处理b
    }
    // 计算前缀和
    for (int i = 1; i <= n; i++) {
        c[i] = b[i] + (i > 1 ? c[i - 1] : 0); // 如果不是第一个元素，则加上前一个元素的前缀和
    }
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        // 查找a中大于等于l的最小元素和大于r的最小元素的前一个位置
        auto l_i = lower_bound(a.begin() + 1, a.end(), l) - a.begin(); // 注意减去begin的指针值
        auto r_i = upper_bound(a.begin() + 1, a.end(), r) - a.begin() - 1; // 注意这里要减2，因为要得到前一个位置
        // 判断边界情况并输出结果
        if (l_i == n && r_i == 0) { // 如果l大于所有元素且r小于所有元素，则输出c[n-1]（假设c[n]是未定义的）
            cout << c[n-1] << endl; // 注意这里要输出n-1的元素，因为c是到n的数组
        } else if (r_i == 0) { // r在所有元素之前
            cout << c[l_i - 1] << endl; // l的前一个元素的前缀和即为所求
        } else if (l_i == n) { // l在所有元素之后
            cout << c[r_i - 1] << endl; // r的后一个元素的前缀和即为所求（假设我们希望输出一个边界之外的值）
        } else { // 如果两者都在数组内且不处于边界情况
            if (l <= a[l_i]) { // l等于其下界的情况，输出相应的前缀和差值（l不包含）
                cout << c[r_i - 1] - c[l_i - 1] << endl;
            } else { // 其他情况直接输出两个索引的前缀和差值（两个值都包含）
                cout << c[r_i] - c[l_i - 1] << endl; // 注意这里输出的是r的索引位置的前缀和减去l的索引位置的前缀和（r是包含的）
            }
        }
    }
    return 0;
}