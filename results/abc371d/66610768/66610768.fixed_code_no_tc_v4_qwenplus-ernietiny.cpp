#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n; // Number of elements in the array a
    vector<int> a(n + 1); // Allocate memory for array a
    for (int i = 1; i <= n; ++i) {
        cin >> a[i]; // Read elements from the array a
    }
    
    // Fixed code block
    while (m--) { // While loop to process multiple cases
        int l, r; // Read the range of interest from the user
        cin >> l >> r; // Read the lower and upper bounds of the range
        auto lower_bound = lower_bound(a.begin(), a.end(), l); // Find the index of element l in array a
        auto upper_bound = upper_bound(a.begin(), a.end(), r); // Find the index of element r in array a
        int i = lower_bound - a.begin(); // Calculate the index of element in array a corresponding to l
        int j = upper_bound - a.begin(); // Calculate the index of element in array a corresponding to r
        // Calculate the difference between corresponding elements in the current range and calculate output
        if (r >= a[n]) { // Check if range [l, r] is within the array bounds
            cout << (r - a[n]) << endl; // If it is, output the difference between corresponding elements in current range and the element at index n in array a
        } else { // If range is not within array bounds, output the difference between corresponding elements in range and the element at index j in array a (since j is the next element after index n)
            cout << (upper_bound - j - 1) - (r - a[n]) << endl; // Calculate difference and output accordingly
        }
    }
    return 0; // Return 0 to indicate successful completion of program
}