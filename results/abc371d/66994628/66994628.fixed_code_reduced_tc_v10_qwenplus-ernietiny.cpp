#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n; // Number of elements in the array x[]
    
    // Initialize the sum array with all elements as zero
    for (int i = 0; i < n; ++i) {
        sum[i] = 0; // Initialize sum array with zero
    }
    
    // Read the elements of x[] and p[]
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> p[i]; // x[] and p[] are the elements to be patched
        // Update the sum array accordingly
        sum[i] = sum[i - 1] + p[i];
    }
    
    // Read the number of queries q
    cin >> q; // Number of queries to be performed
    
    // Initialize the query indices as negative infinity
    vector<int> queryIndices(q); // Initialize query indices array with negative infinity values
    
    // Main query loop
    while (q--) {
        int l, r; // Query indices l and r are read from the input
        cin >> l >> r; // Read the query indices from the input
        
        // Calculate the difference between the left and right indices in the sum array
        int diff = r - l + 1; // Add one to account for the difference in indices
        // Calculate the sum of the elements at the query indices in the sum array
        int result = sum[diff - 1]; // Subtracting the element at index l from the element at index r
        // Output the result as expected by the problem statement
        cout << result << endl; // Output the expected result based on the problem statement
    }
    
    return 0; // Return 0 to indicate successful completion of the program
}