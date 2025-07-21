#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, q;
int x[200005];
int pSum[200005]; // Use an array instead of a map for prefix sum of p

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i]; // Assuming there's another array p to work on
        pSum[i] = pSum[i - 1] + p[i]; // Calculate prefix sum of p
    }
    // Now pSum holds the prefix sum of p. We can perform range sum queries efficiently.
    
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        // Use binary search to find indices for L and R in x, adjust for prefix sum array index.
        int c = lower_bound(x, x + n, L) - x; // c is the index in x where L or a larger value starts. Adjust if needed.
        int d = upper_bound(x, x + n, R) - x - 1; // d is the index before the first occurrence of R or a larger value. Adjust for open range.
        // Check if L is within the range and if so, adjust c accordingly.
        if (c > 0 && x[c - 1] == L) c--; // If L is at the beginning of a range in x, adjust c to exclude it from the query.
        // Now calculate and print the range sum query using pSum array.
        cout << pSum[d] - pSum[c - 1] << endl; // Output the result of the range sum query.
    }
    return 0;
}