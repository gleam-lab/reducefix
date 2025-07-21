#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e6+7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n+1); // 改为直接使用数组，不需要初始化值
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> c(n+1, 0); // 初始化前缀和数组为0
    for (int i = 1; i <= n; i++) {
        c[i] = c[i-1] + a[i]; // 正确计算前缀和
    }
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        // 查找l在a中的位置（注意是闭区间）
        auto l_i = lower_bound(a.begin() + 1, a.end(), l) - a.begin();
        // 查找r在a中的位置（注意是开区间）
        auto r_i = upper_bound(a.begin() + 1, a.end(), r) - a.begin();
        // 如果l在a中找不到，则l_i是未定义值，相当于指向了vector的尾部。我们需要做相应的处理。
        if (l_i == n || a[l_i] != l) { // 调整条件判断，并处理不匹配的情况
            cout << "Not Found" << endl; // 输出"未找到"或其它提示信息，取决于题目要求
        } else { // 否则计算并输出结果
            // 因为r是开区间，所以我们需要确保r的索引没有越界。如果r等于n的话，我们需要特别处理。
            if (r == n) { // r是数组的最后一个元素时的情况处理
                cout << c[r_i] << endl; // 直接输出r的索引对应的前缀和值
            } else { // r不是最后一个元素时的情况处理
                cout << c[r_i] - c[l_i] << endl; // 输出两个索引之间前缀和的差值
            }
        }
    }
    return 0;
}