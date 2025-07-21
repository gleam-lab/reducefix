#include<bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 5; // Define a constant for maximum size of arrays

int n, q, x[MAX], p[MAX]; // Declare arrays for positions and population counts
long long sum[MAX]; // Declare an array for cumulative sums

int main() {
    cin >> n; // Read number of villages
    for (int i = 1; i <= n; i++) {
        cin >> x[i]; // Read position of each village
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i]; // Read population count of each village
        sum[i] = sum[i - 1] + p[i]; // Calculate cumulative sum of populations up to village i
    }

    cin >> q; // Read number of queries
    while (q--) {
        int L, R;
        cin >> L >> R; // Read range for each query
        int l = lower_bound(x + 1, x + n + 1, L) - x; // Find the index of first village not less than L
        int r = upper_bound(x + 1, x + n + 1, R) - x; // Find the index just after last village not greater than R
        if (l > r) { // If no villages lie within the range [L, R]
            cout << 0 << endl; // No villagers in this range
        } else {
            cout << sum[r - 1] - sum[l - 1] << endl; // Print total number of villagers in range [L, R]
        }
    }
    return 0;
}