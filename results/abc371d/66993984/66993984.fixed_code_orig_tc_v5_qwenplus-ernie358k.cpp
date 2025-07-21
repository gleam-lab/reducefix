#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> x(n + 1), p(n + 1); // +1 to use 1-based indexing for simplicity
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    cin >> q;

    // Create a copy of x for sorting
    vector<int> sorted_x(x.begin(), x.end());
    sort(sorted_x.begin(), sorted_x.end());

    // Prefix sums for p
    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + p[i];
    }

    while (q--) {
        int L, R;
        cin >> L >> R;

        // Binary search to find the range in sorted_x
        auto it_L = lower_bound(sorted_x.begin(), sorted_x.end(), L);
        auto it_R = upper_bound(sorted_x.begin(), sorted_x.end(), R);

        int index_L = it_L - sorted_x.begin() + 1; // Convert to 1-based index
        int index_R = it_R - sorted_x.begin(); // 0-based index for upper bound, adjust as needed

        // Adjust index_R if it's out of bounds (should not happen due to upper_bound, but just in case)
        if (index_R > n) index_R = n;

        // Calculate the sum using prefix sums
        long long result = prefix_sum[index_R] - (index_L > 1 ? prefix_sum[index_L - 1] : 0);
        cout << result << endl;
    }

    return 0;
}