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

    sort(a.rbegin(), a.rend());

    vector<ll> pre(N + 5);
    pre[0] = 0LL;
    for (int i = 1; i <= N; ++i) {
        pre[i] = pre[i - 1] + a[i].val;
    }

    K -= pre[N];

    vector<ll> ans(N + 5, -1);

    for (int i = 1; i <= N; ++i) {
        ll need = a[i].val + K;
        int cnt = 0;
        int j = i + 1;
        while (j <= N && a[j].val > need) {
            ++cnt;
            ++j;
        }
        if (cnt >= M) continue;

        need += (M - cnt - 1) * (a[i].val + K + 1);
        ll low = 0, high = K;
        while (low < high) {
            ll mid = (low + high) / 2;
            if (mid + pre[cnt] + need <= pre[N]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        ans[a[i].idx] = low;
    }

    for (int i = 1; i <= N; ++i) {
        if (ans[i] == -1) {
            ans[i] = 0;
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << ans[i] << " ";
    }

    return 0;
}