#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using P = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for(int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        // Sort arrays
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        // Initialize sums and maxima
        ll sumB = 0;
        int maxA = 0;
        for(int i = 0; i < k; ++i) {
            sumB += b[i];
            maxA = max(maxA, a[i]);
        }

        // Calculate initial result
        ll result = maxA * sumB;

        // Sliding window to find the best subset
        for(int i = k; i < n; ++i) {
            sumB -= b[i-k];
            sumB += b[i];
            maxA = max(maxA, a[i]);

            result = min(result, maxA * sumB);
        }

        cout << result << '\n';
    }

    return 0;
}