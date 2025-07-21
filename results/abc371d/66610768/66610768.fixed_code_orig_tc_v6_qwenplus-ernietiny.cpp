#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n; // 输入数据点数量
    vector<int> a(n+1); // 存储每个区间的值
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; // 输入每个区间的值
    }
    
    // 计算区间和并输出结果
    while (m--) {
        int l, r; // 输入区间左端点和右端点
        cin >> l >> r; // 输入区间左端点和右端点
        int result = a[r] - a[l - 1]; // 根据区间和公式计算结果
        cout << result << endl; // 输出结果
    }
    return 0;
}