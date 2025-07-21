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
    
    // Fix the algorithm to handle the case when r is less than l
    // This is necessary to avoid accessing memory beyond bounds when l and r are not present in the array
    if (r < l) {
        // Handle the case when r is less than the first element of array a
        auto it = lower_bound(a.begin(), a.end(), r); // Find the correct index to access c[r]
        if (it == a.end()) { // If r is not present in the array, print an error message
            cout << "Invalid range"; // Or print an appropriate error message based on the context
        } else { // Otherwise, calculate the value of c[r] as per the algorithm
            cout << c[n] - c[it - a.begin() - 1]; // Calculate the value based on the corrected range
        }
    } else { // If r is greater than or equal to the first element of array a
        // The algorithm can be fixed by considering different cases based on whether l is present or not
        // Here, we assume l is present in the array for simplicity and correctness
        auto l_i = upper_bound(a.begin(), a.begin() + n, l); // Find the correct index to access c[l]
        if (l_i == a.end()) { // If l is not present in the array, print an error message
            cout << "Invalid range"; // Or print an appropriate error message based on the context
        } else { // Otherwise, calculate the value of c[l] as per the algorithm
            cout << c[r] - c[l_i - a.begin()]; // Calculate the value based on the corrected range and excluding previous elements of array a
        }
    }
    return 0;
}