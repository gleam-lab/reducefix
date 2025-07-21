#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        ll n, k;
        cin >> n >> k;
        
        vector<ll> a(n), b(n);
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> b[i];
        
        // Sort arrays in descending order
        sort(a.begin(), a.end(), greater<ll>());
        sort(b.begin(), b.end(), greater<ll>());
        
        ll max_a = a[k - 1];
        ll sum_b = accumulate(b.begin(), b.begin() + k, 0LL);
        
        ll result = max_a * sum_b;
        
        // Try to replace the largest elements in a with smaller ones
        for (int i = 1; i <= k; ++i) {
            if (a[i] < a[0]) {
                sum_b -= b[k - i];
                sum_b += b[n - i];
                max_a = a[i];
                result = min(result, max_a * sum_b);
            }
        }
        
        cout << result << endl;
    }

    return 0;
}