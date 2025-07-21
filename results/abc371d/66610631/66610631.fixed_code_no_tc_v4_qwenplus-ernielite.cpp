#include <bits/stdc++.h>
using namespace std;
typedef long long ll; // Use standard 64-bit integer type
const int N = 1e6+7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1); // Use int instead of __int128
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; // Read values into array a
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i]; // Read values into array b (this is not used in provided code)
        if (i > 1) c[i] = c[i - 1] + b[i]; // Calculate cumulative sum in c
    }
    cin >> m; // Read number of queries
    for (int q = 0; q < m; q++) { // Process each query separately
        int l, r;
        cin >> l >> r; // Read query range l and r
        // TODO: Implement the actual logic for processing queries based on your task requirements
        // You may need to sort array a if it's not already sorted or if you need to perform binary search on it.
        // Then you can implement your query processing logic using c and a as needed.
        // ... Your query processing logic here ...
        // For example: Printing out c[r] - c[l-1] if you're trying to find cumulative sum between l and r in c.
        // cout << c[r] - c[l - 1] << endl; // Placeholder for query processing logic
    }
    return 0;
}