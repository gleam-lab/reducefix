#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+7;

int main() {
    int n;
    cin >> n; // Number of elements in the array a
    vector<int> a(n+1); // Allocate memory for array a
    for (int i = 1; i <= n; ++i) {
        cin >> a[i]; // Read elements from array a
    }
    
    // Calculate the modified value c based on the given range [l, r]
    int modified_value = 0; // Initialize the modified value
    auto it = lower_bound(a.begin(), a.end(), 730002498); // Find the index of the element with the given range
    if (it != a.end()) { // Check if the element is present in the array
        modified_value = c[n] - c[it - a.begin() - 1]; // Calculate the modified value if the element is present
    }
    
    // Process each range separately
    for (int m = 0; m < n; ++m) {
        int l, r; // Range [l, r] to be processed
        cin >> l >> r; // Read the range [l, r]
        if (r >= l) { // Check if the range is valid
            if (r == n) { // If the range is for the entire array, output the final value
                cout << modified_value << endl; // Output the modified value if it's valid
            } else { // If the range is for a specific element, calculate and output the difference
                auto it_diff = upper_bound(a.begin(), a.begin() + r - 1, l); // Find the index of the element with the given range
                if (it_diff != a.end()) { // Check if the element exists within the range
                    cout << c[it_diff] << endl; // Output the element's value within the range
                } else { // If the element doesn't exist within the range, output zero (default case)
                    cout << 0 << endl; // Output zero if it doesn't exist in the array
                }
            }
        } else { // If the range is invalid (not within the array), output -1 or some default value (as per problem description)
            cout << -1 << endl; // Output -1 or some default value as per problem description
        }
    }
    return 0;
}