#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<pair<ll, ll>> a(n), b(n);
        
        // Read and store pairs of (A_i, index)
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        
        // Read and store pairs of (B_i, index)
        for (int i = 0; i < n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        // Sort based on the first element of the pair
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        // Create a result array to store the selected elements
        vector<ll> res(k);
        
        // Iterate through the sorted arrays to select the best elements
        for (int i = 0; i < k; ++i) {
            res[i] = a[n - k + i].first * b[a[n - k + i].second].first;
        }
        
        // Find the minimum value among the results
        ll ans = LLONG_MAX;
        for (int i = 0; i < k; ++i) {
            ans = min(ans, res[i]);
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}