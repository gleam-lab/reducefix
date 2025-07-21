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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;

    vector<Node> a(N + 5);

    for (int i = 1; i <= N; ++i) {
        cin >> a[i].val;
        a[i].idx = i;
    }

    auto cmp = [](const auto &A, const auto &B) -> bool {
        return A.val > B.val;
    };

    sort(a.begin() + 1, a.begin() + N + 1, cmp);

    vector<ll> pre(N + 5);
    pre[0] = 0LL;
    for (int i = 1; i <= N; ++i) {
        pre[i] = pre[i - 1] + a[i].val;
    }

    K -= pre[N];

    vector<Node> ans(N + 5);

    for (int i = 1; i <= N; ++i) {
        ans[i].idx = a[i].idx;
        ll cur = a[i].val + K;
        int idx = lower_bound(a.begin() + i + 1, a.begin() + N + 1, (Node){cur, 0}, cmp) - a.begin();
        int cnt = (N - idx + 1);
        if (cnt < M) {
            ans[i].val = -1;
        } else {
            ans[i].val = 0;
        }
    }

    sort(ans.begin() + 1, ans.begin() + N + 1, [](const auto &A, const auto &B) -> bool {
        return A.idx < B.idx;
    });

    for (int i = 1; i <= N; ++i) {
        cout << ans[i].val << ' ';
    }

    return 0;
}