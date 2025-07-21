#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        
        // Sort arrays
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        // Calculate initial sum of B for the first window
        ll current_sum = accumulate(b.begin(), b.begin() + k, 0LL);
        ll result = a[k - 1] * current_sum;
        
        // Sliding window to find the minimum value
        for (int i = k; i < n; ++i) {
            current_sum += b[i] - b[i - k];
            result = min(result, static_cast<ll>(a[i]) * current_sum);
        }
        
        cout << result << '\n';
    }

    return 0;
}