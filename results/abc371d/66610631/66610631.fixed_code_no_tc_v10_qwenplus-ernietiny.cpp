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
    
    // Calculate the modified value of c[n] for the given range [l, r]
    int modified_value = calculateModifiedValue(a, n, m); // Function to calculate the modified value
    
    // Output the result based on the given conditions
    if (m == 0) { // If no more elements to process, just print the final value
        cout << modified_value << endl;
    } else { // Process each range separately
        for (int i = 1; i <= m; ++i) { // Process each range [l, r] separately
            int l_index = lower_bound(a.begin() + 1, a.end(), l); // Find the index of the left boundary in the sorted array
            int r_index = upper_bound(a.begin(), a.end(), r); // Find the index of the right boundary in the sorted array
            if (r_index == n) { // If the range is complete and contains only one element
                cout << modified_value << endl; // Print the final value if it's within the range [l, r]
            } else if (r_index == n - 1) { // If the range is complete and contains only one element at the end
                // Calculate difference between modified value at the end and previous element in the range [l, r]
                int difference = modified_value - c[r_index - a.begin() - 1]; // Calculate difference between modified value and previous element in range [l, r]
                cout << difference << endl; // Print the difference if it's within the range [l, r]
            } else { // If the range is not complete or contains multiple elements
                // Calculate difference between modified value at current element and previous element in range [l, r-1]
                int difference = c[r_index - a.begin() - 1] - c[l_index - a.begin() - 1]; // Calculate difference between modified value at current element and previous element in range [l, r-1]
                cout << difference << endl; // Print the difference if it's within the given range [l, r]
            }
        }
    }
    return 0;
}

// Function to calculate modified value for a given array a and range [l, r]
int calculateModifiedValue(const vector<int>& a, int n, int m) {
    // Your algorithm to calculate modified value goes here. Consider edge cases and constraint limits.
    // This is just an example function to give you an idea of how you can calculate the modified value.
    // In this case, it might involve some arithmetic operations or other algorithms depending on your requirements.
    // Remember to handle edge cases and constraint limits as well as implement the logic accordingly.
    // Note: The actual implementation should handle both cases where r_i==a.end() and where r_i==a[n]. In this example, we assume it's one of these cases.
    return c[n]; // Return the modified value for demonstration purposes. Replace with actual implementation that handles all cases.
}