#include <bits/stdc++.h>
using namespace std;

int n, q;
int p[200005]; // Assuming p[] represents some prefix sum or partial sum array
int sum[200005]; // Sum of elements in p[] up to a given index

int main() {
    cin >> n; // Read number of elements in p[]
    for (int i = 1; i <= n; i++) {
        cin >> p[i]; // Read values into p[]
        if (i > 1) sum[i] = sum[i - 1] + p[i]; // Calculate prefix sum in sum[]
        else sum[i] = p[i]; // Initialize first element of sum[] with p[i]
    }
    
    cin >> q; // Read number of queries
    while (q--) {
        int L, R;
        cin >> L >> R; // Read query range [L, R]
        if (L > R) swap(L, R); // Ensure L <= R for correct output
        // Output the sum of elements in p[] for the range [L, R] (inclusive) using prefix sums
        cout << sum[R] - sum[L - 1] << endl; // Adjusting index for L to get correct prefix sum difference
    }
    return 0; // End of main function with correct return value
}