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
    std::cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M >> K;

    vector<Node> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i].val;
        a[i].idx = i + 1;
    }

    sort(a.begin(), a.end(), [](const Node &x, const Node &y) {
        return x.val < y.val;
    });

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + a[i].val;
    }

    ll remaining = K - prefix[N];

    vector<ll> ans(N);

    for (int i = 0; i < N; ++i) {
        ll low = 0;
        ll high = remaining;
        ll best = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_val = a[i].val + mid;

            int pos = upper_bound(a.begin(), a.end(), Node{new_val, 0}, [](const Node &x, const Node &y) {
                return x.val < y.val;
            }) - a.begin();

            int count = N - pos;
            if (count >= M) {
                low = mid + 1;
                continue;
            }

            ll left = remaining - mid;
            ll required = 0;

            if (pos < N) {
                ll sum = prefix[pos] - prefix[i + 1];
                required = new_val * (pos - i - 1) - sum;
                if (required < 0) required = 0;
            }

            if (required <= left) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        ans[a[i].idx - 1] = best;
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }

    return 0;
}