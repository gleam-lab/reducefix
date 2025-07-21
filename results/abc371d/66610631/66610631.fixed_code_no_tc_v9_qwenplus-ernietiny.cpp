#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n; // Number of elements in the array a
    vector<int> a(n + 1); // Array a with initial values initialized
    for (int i = 1; i <= n; ++i) {
        cin >> a[i]; // Input elements for array a
    }
    
    // Calculate the modified value of c[n] based on the given range
    int modified_value = c(n); // Assuming c is a function that returns the value of array element in the given range
    
    while (m--) { // Process each range of elements
        int l, r; // Range of elements to be processed
        cin >> l >> r; // Input the lower and upper bounds of the range
        
        // Find the correct index to store the modified value
        auto it = lower_bound(a.begin() + 1, a.end(), l); // Find the index of element l in array a
        if (it == a.end()) { // If l is not found in array, it means it's outside the valid range
            cout << modified_value << endl; // Output the modified value outside the valid range
        } else if (r == n) { // If range is completely within array bounds
            cout << modified_value - c[it - a.begin() - 1] << endl; // Output the modified value within the valid range
        } else if (it == a.begin()) { // If range starts at the beginning of array
            cout << c[r] << endl; // Output the modified value at the end of the valid range
        } else { // If range spans multiple elements in array
            cout << (modified_value - c[it - a.begin() - 1] - c[r - it]) << endl; // Calculate the modified value within the valid range by subtracting previous values and current element value
        }
    }
    return 0;
}