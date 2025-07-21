#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using P = pair<int, int>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        VI a(n), b(n);
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());
        
        ll min_product = LLONG_MAX;
        ll sum_b = 0;
        for (int i = 0; i < k; ++i) {
            sum_b += b[i];
        }
        
        min_product = min(min_product, a[0] * sum_b);
        
        // Try to improve the minimum product by swapping elements
        for (int i = 1; i < n && i < k; ++i) {
            ll new_sum_b = sum_b - b[i] + b[0];
            min_product = min(min_product, a[i] * new_sum_b);
            // Swap elements in b
            swap(b[0], b[i]);
        }
        
        cout << min_product << endl;
    }
    return 0;
}