#include<bits/stdc++.h>
using namespace std;

int n, q;
int x[200005]; // Assuming x is the main array we are working with
int sum[200005]; // We will calculate prefix sums here

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    // Assuming x is sorted in this case (or we need to sort it before proceeding)
    // If p is not needed, remove its declaration and related code
    // int p[200005]; // Not used in this code snippet
    // ... p related code ...

    // Calculate prefix sums of x (if necessary)
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + /* some operation on x[i] */; // Replace with actual operation if needed
    }

    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        // Check if L and R are within valid range for binary search
        if (L <= 0 || R > n || L > R) {
            // Handle invalid input or edge case appropriately
            continue; // Or throw an error/warning/set default values as needed
        }
        // Perform binary search as intended using lower_bound and upper_bound (assuming x is sorted)
        int l = lower_bound(x, x + n, L) - x; // Start index of first occurrence of L or greater in x
        int r = upper_bound(x, x + n, R) - x - 1; // End index of last occurrence of R or less in x (excluding R itself)
        // Calculate and print the result based on prefix sums (replace with actual calculation if needed)
        cout << sum[r] - sum[l - 1] << endl; // Corrected range for prefix sum calculation
    }
    return 0;
}