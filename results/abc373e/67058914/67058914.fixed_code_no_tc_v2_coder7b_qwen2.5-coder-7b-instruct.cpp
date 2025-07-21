#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

struct Node {
    ll val;
    int idx;
};

int main() {
    cin >> N >> M >> K;

    vector<Node> a(N + 5);

    for (int i = 1; i <= N; ++i) {
        cin >> a[i].val;
        a[i].idx = i;
    }

    auto cmp = [](const auto &A, const auto &B) -> bool {
        return A.val < B.val;
    };

    sort(a.begin() + 1, a.begin() + N + 1, cmp);

    vector<ll> pre(N + 5);
    pre[0] = 0LL;
    for (int i = 1; i <= N; ++i) {
        pre[i] = pre[i - 1] + a[i].val;
    }

    K -= pre[N];

    vector<ll> ans(N + 5, -1);
    for (int i = 1; i <= N; ++i) {
        if (a[i].val + K >= pre[N]) {
            ans[i] = 0;
            continue;
        }
        int target = lower_bound(a.begin() + i + 1, a.begin() + N + 1, (Node){a[i].val + K + 1, 0}, cmp) - a.begin();
        if (target == N || a[target].val > a[i].val + K) {
            ans[i] = max(0LL, a[i].val + K - pre[target - 1] + 1);
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << ans[i] << ' ';
    }

    return 0;
}