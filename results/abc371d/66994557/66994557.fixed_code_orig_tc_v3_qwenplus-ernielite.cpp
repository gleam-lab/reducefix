#include <bits/stdc++.h>
using namespace std;

int n, q, x[200005], p[200005], sum[400005]; // Increasing the size of sum to handle possible overflow from x[] and p[]

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    sort(x + 1, x + n + 1); // Sorting the array x to ensure correct usage of lower_bound and upper_bound
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i]; // Calculating prefix sum of p[]
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R; // Reading L and R for each query
        int l = lower_bound(x + 1, x + n + 1, L) - x; // Finding the index of L in x[] using lower_bound
        int r = upper_bound(x + 1, x + n + 1, R) - x - 1; // Finding the index of R in x[] using upper_bound and decrementing by 1 to get the previous index (since we use 0-based indexing)
        if (l > r) { // Checking if l is greater than r, indicating an empty range or a mistake in input/sorting
            cout << "-1" << endl; // Outputting -1 for an invalid range or unsorted input/array x[]
        } else {
            cout << sum[r] - sum[l - 1] << endl; // Outputting the result of the query by subtracting the prefix sum at l-1 from the prefix sum at r (inclusive)
        }
    }
    return 0; // Returning 0 to indicate successful execution (although this line is not strictly necessary in C++)
}