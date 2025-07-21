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
    ll sum_a = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum_a += a[i];
    }
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });
    auto b = a;
    sort(all(b));
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = b[i] + pref[i];
    }
    vector<ll> ans(n, -1);
    ll remaining_k = k - sum_a;
    for (int i = 0; i < n; i++) {
        ll low = 0, high = remaining_k;
        ll best_x = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = b[i] + mid;
            int pos = upper_bound(all(b), new_votes) - b.begin();
            int required_pos = n - m;
            if (pos > required_pos) {
                ll sum = pref[n] - pref[required_pos] - (n - required_pos) * new_votes;
                if (sum + mid <= remaining_k) {
                    best_x = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (mid <= remaining_k) {
                    best_x = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        ans[ord[i]] = best_x;
    }
    for (auto x : ans) {
        cout << x << ' ';
    }
    return 0;
}