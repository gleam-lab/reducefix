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
    ll total = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }
    ll remaining = k - total;
    
    vector<ll> b = a;
    sort(b.begin(), b.end());
    
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + b[i];
    }
    
    vector<ll> ans(n, -1);
    for (int i = 0; i < n; i++) {
        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = a[i] + mid;
            
            int pos = upper_bound(b.begin(), b.end(), new_votes) - b.begin();
            int needed = n - m;
            
            if (pos <= needed) {
                best = mid;
                high = mid - 1;
            } else {
                ll sum = pref[n] - pref[pos] - (n - pos) * new_votes;
                if (sum <= remaining - mid) {
                    best = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        ans[i] = best;
    }
    
    for (int i = 0; i < n; i++) {
        if (ans[i] != -1 && ans[i] <= remaining) {
            cout << ans[i] << " ";
        } else {
            cout << "-1 ";
        }
    }
    cout << endl;
    
    return 0;
}