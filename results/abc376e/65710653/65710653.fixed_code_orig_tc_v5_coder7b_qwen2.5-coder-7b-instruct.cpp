#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

        // Select the last k elements from both arrays
        int max_a = a[n - k];
        int sum_b = 0;
        for (int i = n - k; i < n; ++i) {
            sum_b += b[i];
        }

        // Calculate the result
        long long result = static_cast<long long>(max_a) * sum_b;
        cout << result << '\n';
    }

    return 0;
}