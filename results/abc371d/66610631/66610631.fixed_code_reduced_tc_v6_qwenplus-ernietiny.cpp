#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+7;

int main() {
    int n, m;
    cin >> n; // Number of elements in the array a
    vector<int> a(n+1); // Preallocate the array for easier reading
    for (int i = 1; i <= n; ++i) {
        cin >> a[i]; // Input elements in array a
    }
    
    // Sort the array in ascending order to handle the range query efficiently
    sort(a.begin(), a.end());
    
    while (m--) { // Process m queries
        int l, r; // Query indices for left and right bounds
        cin >> l >> r; // Input the query indices
        
        // Handle the special cases where l and r are at the end of the array
        if (l == n || r == n) { // If either l or r is at the end, return the element at index n-1
            cout << a[n-1] << endl; // Output the element at index n-1
        } else if (r >= n) { // If r is greater than or equal to the length of array, return difference between previous element and current element
            cout << a[r] - a[r - n] << endl; // Calculate difference between current element and previous element at index r-n and output it
        } else { // For other cases, calculate the difference between the current element and previous element at left and right bounds
            int left_bound = lower_bound(a.begin(), a.begin() + l - 1, l) - a.begin(); // Left boundary index of the current element
            int right_bound = upper_bound(a.begin() + r - 1, a.end(), r) - a.begin(); // Right boundary index of the current element
            cout << (right_bound < left_bound ? left_bound : right_bound) << endl; // Return the minimum of the two bounds if it's smaller or equal to each other
        }
    }
    return 0;
}