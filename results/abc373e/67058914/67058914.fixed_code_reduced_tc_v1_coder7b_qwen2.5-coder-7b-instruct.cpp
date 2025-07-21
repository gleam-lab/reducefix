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

    sort(a.begin() + 1, a.begin() + N + 1, [](const auto &A, const auto &B) -> bool {
        return A.val < B.val;
    });

    vector<ll> pre(N + 5);
    pre[0] = 0LL;
    for (int i = 1; i <= N; ++i) {
        pre[i] = pre[i - 1] + a[i].val;
    }

    K -= pre[N];

    vector<ll> ans(N + 5, -1);
    for (int i = 1; i <= N; ++i) {
        ll cur = a[i].val + K;
        int idx = upper_bound(a.begin() + i + 1, a.begin() + N + 1, (Node){cur, 0}, [](const auto &A, const auto &B) -> bool {
            return A.val < B.val;
        }) - a.begin();
        int cnt = (N - idx + 1);
        if (cnt >= M) {
            ans[i] = -1;
            continue;
        }
        ll needed = (a[idx].val - cur) * (M - cnt) + (K - (pre[idx] - pre[i]));
        ans[i] = needed;
    }

    sort(ans.begin() + 1, ans.begin() + N + 1, [](const auto &A, const auto &B) -> bool {
        return A.second < B.second;
    });

    for (int i = 1; i <= N; ++i) {
        cout << ans[i] << ' ';
    }

    return 0;
}