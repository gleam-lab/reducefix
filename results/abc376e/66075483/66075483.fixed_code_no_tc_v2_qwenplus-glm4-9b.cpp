#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define LL long long
const int N = 2e5 + 9;

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<LL> A(n), B(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> B[i];
        }

        // Sort A and keep track of original indices
        vector<pair<LL, int>> indexed_A(n);
        for (int i = 0; i < n; i++) {
            indexed_A[i] = {A[i], i};
        }
        sort(indexed_A.begin(), indexed_A.end());

        // Calculate prefix sums of B
        vector<LL> prefix_sum_B(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix_sum_B[i] = prefix_sum_B[i - 1] + B[indexed_A[i - 1].second];
        }

        // Find the minimum possible value of the expression
        LL ans = LLONG_MAX;
        for (int i = 0; i <= n - k; i++) {
            LL sum_B = prefix_sum_B[i + k] - prefix_sum_B[i];
            LL max_A = indexed_A[i + k - 1].first;
            ans = min(ans, max_A * sum_B);
        }
        cout << ans << endl;
    }
    return 0;
}