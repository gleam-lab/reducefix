#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+7;

int main() {
    int n;
    cin >> n; // Number of elements in the array a
    vector<int> a(n+1); // Preallocate array for simplicity
    for (int i = 1; i <= n; ++i) {
        cin >> a[i]; // Input elements in array a
    }
    
    // Initialize the modified array c with values computed by previous calculations
    for (int i = 0; i < n; ++i) {
        c[i] = a[i] + c[i-1]; // Update array c with previous calculation
    }
    
    int m; // Number of queries to be processed
    cin >> m; // Input the number of queries
    while (m--) { // Process each query
        int l, r; // Input the lower and upper bounds for query range
        cin >> l >> r; // Input the lower and upper bounds for the query range
        auto i = lower_bound(a.begin() + 1, a.end(), l); // Find index of element to compare with the range bounds
        auto j = upper_bound(a.begin(), a.end(), r); // Find index of element to compare with the range bounds in array a
        // Calculate the difference between modified array c and original array b
        int diff = c[j] - c[i-1]; // This line is incorrect as it is not using the modified array c properly
        // Corrected line: Output the difference as required
        cout << diff << endl; // Output the difference as expected by the problem description
    }
    return 0;
}