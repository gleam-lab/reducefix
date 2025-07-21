#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort candidates by their votes in descending order
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] > a[j]; });

    vector<ll> b(a), pref(n + 1);
    sort(b.begin(), b.end());
    for (int i = 0; i <= n; i++) {
        pref[i + 1] = pref[i] + b[i];
    }

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; i++) {
        int idx = ord[i];
        ll current_votes = a[idx];
        int max_rivals = (n - i - 1 < m - 1) ? n - i - 1 : m - 1;
        ll votes_needed = max_rivals * (current_votes + 1) - (pref[max_rivals + 1] - pref[i + 1]);

        // Binary search for the minimum additional votes needed
        if (votes_needed > k) {
            ans[idx] = -1;
        } else {
            ll low = 0, high = k - votes_needed;
            while (low < high) {
                ll mid = (low + high) / 2;
                if (current_votes + mid + 1 >= b[i + max_rivals + 1]) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            ans[idx] = low;
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}