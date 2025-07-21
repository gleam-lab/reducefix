#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    ll val;
    int idx;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N, M;
    ll K;
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

    vector<ll> ans(N + 5, 0);
    for (int i = 1; i <= N; ++i) {
        ll remain = K - a[i].val;
        ll cur = a[i].val + 1;
        int L = 0, R = N - i;
        while (L < R) {
            int MID = (L + R + 1) >> 1;
            ll need = cur * MID - (pre[N] - pre[N - MID]);
            if (N - MID < i) {
                need -= (a[i].val + 1);
            }
            if (need > remain) R = MID - 1;
            else L = MID;
        }
        ans[a[i].idx] = L - (N - L < i);
    }

    for (int i = 1; i <= N; ++i) {
        if (ans[i] == 0 && a[i].val + K < a[M]) ans[i] = -1;
    }

    for (int i = 1; i <= N; ++i) {
        cout << ans[i] << ' ';
    }

    return 0;
}