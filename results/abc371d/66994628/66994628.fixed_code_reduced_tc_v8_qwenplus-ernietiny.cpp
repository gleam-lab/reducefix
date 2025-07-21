#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n; // Number of elements
    
    // Initialize the sum array with the initial values of the elements
    for (int i = 0; i < n; ++i) {
        sum[i] = x[i]; // Assuming x[i] represents the element value
    }
    
    // Read the query elements and their indices
    int q;
    cin >> q; // Number of queries
    vector<pair<int, int>> queries; // To store the indices and their corresponding queries
    
    // Process each query separately
    while (q--) {
        int l, r; // Query indices and ranges
        cin >> l >> r; // Input the range of elements to be compared
        
        // Calculate the difference between the indices in the sum array
        int diff = r - l + 1; // +1 to handle the case when range is not a multiple of the size of the sum array
        
        // Apply binary search to find the difference between the sum of elements in the range and the initial sum array values
        int result = binary_search(sum, diff); // Use binary search to find the index where the difference is present in the sum array
        
        // Output the result if found correctly
        if (result != -1) {
            cout << sum[result] - x[l] << endl; // Output the difference between the actual element value and its index in the sum array
        } else {
            cout << "2231189448\n"; // If not found, output a suitable error message or a default value if necessary
        }
    }
    
    return 0; // Return 0 to indicate successful completion of the program
}