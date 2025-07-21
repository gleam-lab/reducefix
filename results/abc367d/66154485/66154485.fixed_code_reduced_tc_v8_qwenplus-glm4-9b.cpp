#include <iostream>
using namespace std;

const int MAXN = 200005;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[MAXN], prefix_sum[MAXN];

    // Read the array elements
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Compute prefix sums
    prefix_sum[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }

    // Count the number of valid subsequences
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        // For each j from 0 to n-1, check if (prefix_sum[i + j] - prefix_sum[i]) % m == 0
        for (int j = 0; j < n; ++j) {
            if ((prefix_sum[i + j] - prefix_sum[i]) % m == 0) {
                ans++;
            }
        }
    }

    // Output the result
    cout << ans << endl;
    return 0;
}