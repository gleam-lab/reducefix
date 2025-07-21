#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> B[i];
        }
        
        // Pairing A and B and sorting by A
        vector<pair<int, int>> ab(n);
        for (int i = 0; i < n; i++) {
            ab[i] = {A[i], B[i]};
        }
        sort(ab.begin(), ab.end());
        
        // Initial window
        long long sumB = 0, maxA = ab[0].first;
        for (int i = 1; i <= k; i++) {
            sumB += ab[i - 1].second;
        }
        
        long long ans = maxA * sumB;
        
        // Sliding window
        for (int i = k; i < n; i++) {
            sumB += ab[i].second - ab[i - k].second;
            maxA = ab[i - k + 1].first;
            ans = min(ans, maxA * sumB);
        }
        
        cout << ans << '\n';
    }
    return 0;
}