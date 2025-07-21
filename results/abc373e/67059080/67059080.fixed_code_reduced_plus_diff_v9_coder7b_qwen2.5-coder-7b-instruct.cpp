#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

struct Node {
    ll val;
    int idx;
};

bool canWin(const vector<Node>& a, ll add, int i) {
    int cnt = 0;
    for (int j = 0; j < N; ++j) {
        if (j != i && a[j].val + add > a[i].val) {
            ++cnt;
        }
        if (cnt >= M) break;
    }
    return cnt == M - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;

    vector<Node> a(N + 5);

    for (int i = 1; i <= N; ++i) {
        cin >> a[i].val;
        a[i].idx = i;
    }

    sort(a.begin() + 1, a.begin() + N + 1);

    vector<ll> pre(N + 5);
    pre[0] = 0LL;
    for (int i = 1; i <= N; ++i) {
        pre[i] = pre[i - 1] + a[i].val;
    }

    K -= pre[N];

    vector<ll> ans(N + 5, -1);

    for (int i = 1; i <= N; ++i) {
        if (a[i].idx != 1) {
            ans[a[i].idx] = 0;
            continue;
        }

        ll low = 0, high = K;
        while (low <= high) {
            ll mid = (low + high) / 2;
            if (canWin(a, mid, i)) {
                ans[a[i].idx] = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}