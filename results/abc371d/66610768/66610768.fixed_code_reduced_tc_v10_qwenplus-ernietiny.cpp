#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+7;

int main() {
    int n;
    cin >> n; // Number of elements in the array a
    vector<int> a(n+1); // Preallocate array for simplicity
    for (int i = 1; i <= n; ++i) {
        cin >> a[i]; // Input elements in array a
    }
    
    // Function to calculate the difference between two numbers in sorted array
    int diff(int x, int y) {
        return lower_bound(a.begin(), a.end(), x) - upper_bound(a.begin(), a.end(), y);
    }
    
    // Process each case separately
    while (cin >> m) { // While we have input for m cases
        for (int i = 0; i < n; ++i) { // Process each element separately
            int l, r; // Current lower and upper bounds for comparison
            cin >> l >> r; // Input the range of the current element
            // Find the indices of the element within the sorted array
            auto it = lower_bound(a.begin(), a.end(), l); // It will be an index into sorted array
            auto it_prev = --it; // Index of the previous element to compare with
            int diffPrev = diff(l, it_prev); // Calculate difference for previous element
            if (r >= a[n]) { // If the range includes the last element, calculate the difference as before
                cout << diffPrev << endl; // Output the difference before the last element if it exists
            } else { // Otherwise, calculate the difference between current element and range end index
                cout << diff(a[n], r) << endl; // Output the difference between current element and range end index if it exists
            }
        }
    }
    return 0;
}