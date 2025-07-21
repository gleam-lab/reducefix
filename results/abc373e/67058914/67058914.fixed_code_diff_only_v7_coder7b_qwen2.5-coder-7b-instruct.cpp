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

    vector<ll> ans(N + 5, -1); // Initialize answer array with -1
    vector<bool> elected(N + 5, false); // Track if a candidate is already elected

    for (int i = 1; i <= N; ++i) {
        if (elected[i]) continue;

        ll cur = a[i].val + K;
        int idx = upper_bound(a.begin() + i + 1, a.begin() + N + 1, (Node){cur, 0}, cmp) - a.begin();
        int cnt = (N - idx + 1);

        if (cnt >= M) {
            ans[i] = 0; // Already elected
            elected[i] = true;
            continue;
        }

        ll need = (M - cnt) * (a[idx].val - a[i].val);
        if (need <= K) {
            ans[i] = need;
            elected[i] = true;
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << ans[i] << ' ';
    }

    return 0;
}