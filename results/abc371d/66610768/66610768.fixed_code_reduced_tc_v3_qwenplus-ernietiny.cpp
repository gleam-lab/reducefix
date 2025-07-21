#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; // Number of elements in the array a
    vector<int> a(n+1); // Create an array of size n+1 to store the elements
    for (int i = 1; i <= n; ++i) {
        cin >> a[i]; // Read the elements from the array
    }
    
    // Sort the array in ascending order to handle range queries efficiently
    sort(a.begin(), a.end());
    
    int m; // Number of queries
    cin >> m; // Number of queries to process
    
    while (m--) { // Process each query
        int l, r; // Range query values
        cin >> l >> r; // Read the range query values
        // Calculate the difference between the two elements in the range
        int diff = (r >= a[n]) ? c[n] - c[l-1] : c[r-1] - c[n]; // Handle the case when range is greater than the array size
        cout << diff << endl; // Output the result
    }
    return 0;
}