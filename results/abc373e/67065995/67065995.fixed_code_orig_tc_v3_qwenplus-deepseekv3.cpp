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
    for(int i=0;i<n;i++) {
        cin >> a[i];
        total += a[i];
    }
    ll remaining = k - total;

    if (m == n) {
        for(int i=0;i<n;i++) {
            cout << 0 << ' ';
        }
        return 0;
    }

    vector<pair<ll, int>> b(n);
    for(int i=0;i<n;i++) {
        b[i] = {a[i], i};
    }
    sort(b.begin(), b.end());

    vector<ll> ans(n, -1);
    for(int i=0;i<n;i++) {
        ll current = b[i].first;
        int idx = b[i].second;
        
        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            
            ll new_val = current + mid;
            auto it = upper_bound(b.begin(), b.end(), make_pair(new_val, n));
            int count = b.end() - it;
            
            if (count < m) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (best != -1) {
            ans[idx] = best;
        }
    }
    
    for(auto x : ans) {
        cout << x << ' ';
    }
    return 0;
}