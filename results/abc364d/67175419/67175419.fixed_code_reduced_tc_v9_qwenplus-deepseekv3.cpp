#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
int n, q;
vector<ll> a;

bool check(ll mid, ll b, int k) {
    ll left = b - mid;
    ll right = b + mid;
    int l = lower_bound(a.begin(), a.end(), left) - a.begin();
    int r = upper_bound(a.begin(), a.end(), right) - a.begin();
    return (r - l) >= k;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    while (q--) {
        ll b;
        int k;
        cin >> b >> k;
        
        ll low = 0, high = 2e18;
        ll ans = high;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (check(mid, b, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}