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
    ll total_used = accumulate(all(a), 0LL);
    ll remaining = k - total_used;

    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });
    auto b = a;
    sort(all(b));
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + b[i];
    }

    vector<ll> ans(n, -1);
    for (int idx = 0; idx < n; idx++) {
        int i = ord[idx];
        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_val = a[i] + mid;
            auto it = upper_bound(all(b), new_val);
            int count_greater = b.end() - it;
            if (count_greater < m) {
                best = mid;
                high = mid - 1;
            } else {
                ll required = 0;
                int pos = it - b.begin();
                int from = n - m;
                if (pos > from) {
                    required += (pref[n] - pref[from]) - (new_val * (n - from)) + (n - from);
                    if (required <= remaining - mid) {
                        best = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                } else {
                    low = mid + 1;
                }
            }
        }
        ans[i] = best;
    }
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}