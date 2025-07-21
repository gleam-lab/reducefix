#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i,n) for (int i = 0; i < (n); ++i)
// 其他宏定义保持不变...

int main() {
    int N;
    cin >> N;
    vector<ll> prefixSum(N + 1, 0); // 使用前缀和数组而不是差分数组
    rep(i, N) {
        int p;
        cin >> p;
        prefixSum[i + 1] = prefixSum[i] + p; // 累加差分数组元素到前缀和数组中
    }
    // 下面部分保持不变...（初始化x_to_ptr等）

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R; // 注意这里不需要再定义l和r，因为直接使用prefixSum数组进行计算
        cin >> L >> R;
        // 使用二分查找确定L和R在x_to_ptr中的位置（注意处理边界情况）
        auto X_l = x_to_ptr.lower_bound(L);
        auto X_r = x_to_ptr.upper_bound(R);
        int idx_l = X_l == x_to_ptr.begin() ? -1 : (X_l - 1)->second; // 处理边界情况，确保idx_l有效
        int idx_r = X_r != x_to_ptr.end() ? X_r->second : N; // 确保idx_r有效且不超过N
        // 计算并输出结果（注意是prefixSum[idx_r] - prefixSum[idx_l]，而不是P数组）
        int ans = prefixSum[idx_r] - (idx_l == -1 ? 0 : prefixSum[idx_l]); // 如果L不在x中，则使用0作为起始点前缀和
        cout << ans << endl;
    }
}