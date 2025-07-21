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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });
    
    vector<ll> b = a;
    sort(all(b));
    
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + b[i];
    }
    
    vector<ll> ans(n, -1);
    ll remaining_votes = k - accumulate(all(a), 0LL);
    
    for (int i = 0; i < n; ++i) {
        ll low = 0, high = remaining_votes;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = a[ord[i]] + mid;
            
            int pos = upper_bound(all(b), new_votes) - b.begin();
            int needed = n - pos;
            
            if (needed < m) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        ans[ord[i]] = best;
    }
    
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}