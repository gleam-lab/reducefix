#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Precompute prefix sums
    vector<int> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + arr[i];
    }

    int ans = 0;

    // Calculate the number of valid answers
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int sum = prefix_sum[j] - prefix_sum[i];
            if (sum % m == 0) {
                ans++;
            }
        }
    }

    cout << ans;
    return 0;
}