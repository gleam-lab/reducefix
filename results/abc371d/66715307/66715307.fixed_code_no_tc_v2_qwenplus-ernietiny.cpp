#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n; // Read the number of elements
    
    // Create the arrays for x and p based on the given inputs
    vector<int> x(n); // Assuming x[] represents sorted elements
    vector<int> p(n); // Assuming p[] represents sorted indices
    
    // Process the array elements and store their sum in a variable 'a'
    for (int i = 1; i <= n; i++) {
        cin >> x[i]; // Read elements for current index
        p[i] = i; // Assuming p[i] is the current index of the element
        a[i] = x[i] + p[i]; // Calculate the sum of elements at current index
    }
    
    // Read the number of queries q
    cin >> q; // Read the number of queries
    
    // Process each query separately and print the result
    for (int i = 0; i < q; i++) {
        int l, r; // Read the left and right indices for each query
        cin >> l >> r; // Read the left and right indices for each query
        
        // Calculate the sum of elements in the range [l, r] using binary search
        int l1 = binary_search(x.begin(), x.begin() + l); // Binary search based on the left index for each query
        int r1 = binary_search(x.begin() + l + 1, x.end()); // Binary search based on the right index for each query
        
        // Print the result of calculating difference between first element and the last element of range [l, r]
        cout << a[r1] - a[l - 1] << endl; // The result will be a number in between 0 to max_value inclusive, where max_value is the total sum of elements before query indices
    }
    
    return 0; // Return 0 to indicate successful completion of program execution
}