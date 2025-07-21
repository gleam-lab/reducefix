#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[200005];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Precompute prefix sums modulo m to avoid recomputation
    int prefix_sum[n];
    prefix_sum[0] = arr[0] % m;
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = (prefix_sum[i - 1] + arr[i]) % m;
    }

    int ans = 0;
    // We only need to consider j from 0 to n-1
    for (int j = 0; j < n; j++) {
        int sum = (prefix_sum[(j + n - 1) % n] - prefix_sum[j] + m) % m; // Adjust for negative values
        if (sum == 0) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}