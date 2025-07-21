#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

// 省略了其他定义部分...

int main() {
    int N;
    cin >> N;
    vector<int> P(N + 1, 0); // 初始化P数组为全零，确保每个元素都从0开始累加
    vector<int> X(N);
    rep(i, N) {
        cin >> X[i];
        P[i + 1] = P[i] + X[i]; // 正确计算累加和，从P[1]开始累加每个X[i]的值
    }
    // ... 其他部分保持不变 ...

    // 省略了其他输入和输出的部分...

    return 0; // 添加返回语句，虽然不是错误但良好的习惯是总是返回一个值
}