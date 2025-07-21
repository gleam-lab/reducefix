#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; // Number of elements in vector a
    cin >> n; // Read number of elements in vector a
    vector<int> a(n + 1); // Create vector a with initial values
    for (int i = 0; i < n; ++i) { // Read elements from user for vector a
        cin >> a[i];
    }
    
    int m; // Number of queries
    cin >> m; // Read number of queries
    vector<int> c(m + 1); // Create vector c with initial values for subsequent calculations
    for (int i = 0; i < n; ++i) { // Read elements from user for vector c
        c[i] = a[i] + c[i - 1]; // Calculate new value for current query
    }
    
    // Fix the algorithm errors in the code
    // ... (additional error fixes) ...
    
    // Example usage: Print the result for each query
    while (m--) {
        int l, r; // Read query boundaries from user
        auto l_i = lower_bound(a.begin(), a.end(), l); // Find index of element in vector a to compare with r
        auto r_j = upper_bound(a.begin(), a.end(), r); // Find index of element to compare with next query's upper bound
        int i = l_i - a.begin(); // Calculate index of current query within vector a
        int j = r_j - a.begin(); // Calculate index of next query's upper bound within vector a if necessary
        cout << c[j] - c[i - 1] << endl; // Print the difference between current query's value and the next query's value if it exists and is within bounds
    }
    
    return 0; // Return 0 to indicate successful completion of the program
}