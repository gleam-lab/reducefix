#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll total_current = accumulate(all(a), 0LL);
    ll remaining = k - total_current;

    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });
    vector<ll> sorted_a = a;
    sort(all(sorted_a));

    vector<ll> ans(n, -1);

    for (int idx = 0; idx < n; idx++) {
        int i = ord[idx];
        ll current = a[i];

        // Binary search on minimum X additional votes needed
        ll low = 0, high = remaining;
        ll res = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll target = current + mid;

            // We need to ensure that at most M-1 candidates have more than target votes
            // So find how many candidates can potentially get > target votes
            int cnt = n - (upper_bound(all(sorted_a), target) - sorted_a.begin());

            if (cnt <= m - 1) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        ans[i] = (res == -1 ? -1 : res);
    }

    for (auto x : ans)
        cout << (x >= 0 ? x : 0) << " ";
    cout << "\n";
}