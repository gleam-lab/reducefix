#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < n; i++) cin >> B[i];
        sort(A.rbegin(), A.rend());
        sort(B.rbegin(), B.rend());
        vector<int> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + B[i - 1];
        }
        long long ans = LLONG_MAX;
        for (int i = 0; i < n - (k - 1); i++) {
            if (prefixSum[i + k - 1] - prefixSum[i] >= k) {
                ans = min(ans, (long long)A[i] * (prefixSum[i + k - 1] - prefixSum[i]));
            }
        }
        for (int i = 0; i < n; i++) {
            ans = min(ans, (long long)A[i] * prefixSum[i]);
        }
        cout << ans << endl;
    }
    return 0;
}