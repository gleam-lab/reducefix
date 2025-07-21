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

    vector<Node> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i].val;
        a[i].idx = i + 1;
    }

    sort(a.begin(), a.end(), [](const Node &x, const Node &y) {
        return x.val < y.val;
    });

    vector<ll> pre(N + 1);
    pre[0] = 0;
    for (int i = 1; i <= N; ++i) {
        pre[i] = pre[i - 1] + a[i - 1].val;
    }

    ll remaining = K - pre[N];

    vector<ll> ans(N);
    for (int i = 0; i < N; ++i) {
        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total = a[i].val + mid;
            int pos = upper_bound(a.begin(), a.end(), Node{total, 0}, [](const Node &x, const Node &y) {
                return x.val < y.val;
            }) - a.begin();
            int cnt = N - pos;
            if (cnt < M) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        ans[a[i].idx - 1] = (best == -1) ? -1 : best;
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}