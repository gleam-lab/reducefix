#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x[200050], p[200050], q; // Replace 200050 with actual values
    cin >> n; // Read number of elements
    for (int i = 1; i <= n; i++) cin >> x[i]; // Read elements for each patch

    // Patch calculation and results
    int a[n + 1]; // Using array of pointers to avoid using additional space
    for (int i = 1; i <= n; i++) {
        a[x[i]]++; // Patch value added to the corresponding patch index
    }
    cin >> q; // Read number of queries
    for (int i = 1; i <= q; i++) {
        int l, r; // Read left and right boundaries for each query
        cin >> l >> r; // Read the query value and its boundaries
        // Calculate the difference between adjacent patches that satisfy the query range
        int diff = 0; // Initialize the difference variable
        int l1 = 1, r1 = n; // Initialize left and right pointers to the first patch index
        while (l1 <= r1) { // Loop until both pointers are within the valid range of patches
            int mid = l1 + (r1 - l1) / 2; // Calculate mid index
            if (a[mid] >= l) r1 = mid - 1; // If patch value is greater than or equal to the left boundary, move right pointer
            else diff += a[mid] - a[l]; // Otherwise, add the difference between adjacent patches that satisfy the query range
        }
        // Output the result for the query range
        cout << diff << endl; // Output the result for the query range
    }
    return 0;
}