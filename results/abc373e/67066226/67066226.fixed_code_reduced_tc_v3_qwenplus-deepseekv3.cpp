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
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    ll remaining = k - sum;

    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });
    vector<ll> b = a;
    sort(all(b));

    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + b[i];
    }

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; i++) {
        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total = a[i] + mid;
            ll pos = upper_bound(all(b), total) - b.begin();
            if (n - pos < m) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (best != -1 && best <= remaining) {
            ans[i] = best;
        }
    }

    vector<ll> final_ans(n);
    for (int i = 0; i < n; i++) {
        final_ans[ord[i]] = ans[i];
    }

    for (int i = 0; i < n; i++) {
        cout << final_ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}