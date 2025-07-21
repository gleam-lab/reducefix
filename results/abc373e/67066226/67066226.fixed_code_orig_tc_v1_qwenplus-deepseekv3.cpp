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
    
    vector<ll> b = a;
    sort(all(b));
    
    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + b[i];
    }
    
    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        ll current = a[i];
        // Find the position in the sorted array
        int pos = lower_bound(all(b), current) - b.begin();
        
        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current + mid;
            
            // Find the first element >= new_votes in b
            int new_pos = upper_bound(all(b), new_votes) - b.begin();
            
            // The number of elements >= new_votes is (n - new_pos)
            // We need (n - new_pos) < m
            if (n - new_pos < m) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (best != -1) {
            ans[i] = best;
        } else {
            ans[i] = -1;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}