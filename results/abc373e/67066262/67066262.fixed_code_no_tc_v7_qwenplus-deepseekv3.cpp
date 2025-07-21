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
    ll total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total += a[i];
    }
    ll remaining = k - total;
    
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });
    vector<ll> sorted_a = a;
    sort(all(sorted_a));
    
    vector<ll> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + sorted_a[i];
    }
    
    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        ll original = a[ord[i]];
        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = original + mid;
            
            // Find the number of candidates with votes > new_votes
            auto it = upper_bound(all(sorted_a), new_votes);
            ll cnt = sorted_a.end() - it;
            
            if (new_votes > sorted_a[n - m]) {
                cnt = n - m - (binary_search(all(sorted_a), new_votes) ? 1 : 0);
            } else {
                cnt = n - (it - sorted_a.begin());
            }
            
            if (cnt < m) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (best != -1 && best <= remaining) {
            ans[ord[i]] = best;
        } else {
            ans[ord[i]] = -1;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}