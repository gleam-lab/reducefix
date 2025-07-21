#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<long long> x(n + 1), p(n + 1); // Use vectors for dynamic array handling and zero-indexing
    vector<long long> sum(n + 1, 0); // Prefix sum array initialized to zero

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i]; // Correct prefix sum calculation for zero-indexed access
    }

    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        auto it_l = lower_bound(x.begin() + 1, x.end(), L) - x.begin(); // Use begin() + 1 for zero-indexed array
        auto it_r = upper_bound(x.begin() + 1, x.end(), R) - x.begin(); // Use begin() + 1 for zero-indexed array

        // Handle edge cases where L or R are not found in x
        if (it_l == n + 1 || x[it_l] > L) it_l--; // Adjust if L is not found but should be included
        if (it_r != 0 && x[it_r - 1] <= R) it_r--; // Adjust if R is found but should be excluded (upper_bound gives the first position greater than R)

        // Output the result, ensuring no out-of-bounds access
        cout << (it_r > it_l ? sum[it_r] - sum[it_l] : 0) << endl;
    }

    return 0;
}