#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> A(n), B(n);
        for(int i = 0; i < n; ++i) cin >> A[i];
        for(int i = 0; i < n; ++i) cin >> B[i];

        // Sort both arrays
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        // Initialize pointers and variables
        int i = 0, j = 0;
        int max_A = A[k-1]; // Maximum element in the first k elements of A
        int sum_B = 0; // Sum of the first k elements of B
        for(int l = 0; l < k; ++l) sum_B += B[l];

        int result = max_A * sum_B;

        // Use two-pointer technique to find the optimal subset
        while(i + k <= n && j + k <= n) {
            // Update max_A and sum_B for the next window
            max_A = A[i + k - 1];
            sum_B -= B[j++];
            sum_B += B[i + k++];

            // Calculate the new product and update the result if smaller
            result = min(result, max_A * sum_B);
        }

        cout << result << '\n';
    }
    return 0;
}