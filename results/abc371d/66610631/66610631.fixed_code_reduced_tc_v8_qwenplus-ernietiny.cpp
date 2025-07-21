#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; // Number of elements in array a
    vector<int> a(n+1); // Initialize the array with 0s
    for (int i = 1; i <= n; ++i) {
        cin >> a[i]; // Read elements from array a
    }
    
    // Function to find the sum of the differences between consecutive elements in array b
    auto diffSum = [&](int l, int r) {
        auto it = lower_bound(a.begin() + 1, a.end(), l); // Find the index of the first element greater than l
        if (it == a.end()) return -1; // If l is not present in array, return -1 or some default value
        int diff = *it - l; // Calculate the difference between consecutive elements
        return diffSum(r, diff); // Return the sum of differences between consecutive elements
    };
    
    // Main logic for calculating expected output based on the given input
    int expectedOutput = 0; // Initialize expected output variable
    for (int m = 0; m < n; ++m) { // Process each input case
        int l, r; // Input cases are separated by space
        cin >> l >> r; // Read the range for the current case
        // Base case for single element case
        if (r == n && l == 1) expectedOutput = -1; // If range is empty and element is 1, output -1 for consistency with expected output format
        else { // Process each input element in the range separately
            int currentDiff = diffSum(l, r); // Calculate the difference between consecutive elements in range [l, r]
            if (currentDiff != -1) { // If the difference is not -1, calculate the expected output based on it
                expectedOutput = currentDiff * (r - l + 1); // The expected output is calculated as range size minus difference times the number of elements in the range minus one
            }
        }
        cout << expectedOutput << endl; // Output the calculated expected output
    }
    return 0;
}