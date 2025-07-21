#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    ll val;
    int idx;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<Node> a(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> a[i].val;
        a[i].idx = i;
    }

    sort(a.rbegin(), a.rend());

    vector<ll> pre(N + 1);
    pre[0] = 0;
    for (int i = 1; i <= N; ++i) {
        pre[i] = pre[i - 1] + a[i].val;
    }

    K -= pre[N];

    vector<ll> ans(N + 1, -1);

    for (int i = 1; i <= N; ++i) {
        int cnt = N - i;
        if (cnt < M) {
            ans[a[i].idx] = 0;
            continue;
        }

        ll target = a[i].val + 1;
        int left = 0, right = K;
        while (left < right) {
            int mid = (left + right) / 2;
            ll need = target * (mid + 1) - (pre[N] - pre[i]) - (mid + 1);
            if (need > K) right = mid;
            else left = mid + 1;
        }

        ans[a[i].idx] = max(0LL, left - (N - i));
    }

    for (int i = 1; i <= N; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}