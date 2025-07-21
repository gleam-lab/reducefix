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
        if (it == a.end()) { // If r is not present in the array, print as is
            cout << c[n] << endl; // Print the value of c[n] as it was before the modification
        } else { // Otherwise, calculate the difference and print accordingly
            cout << c[n] - c[it - a.begin() - 1] << endl; // Calculate the difference between c[r] and the value stored at c[n] minus the difference between the previous value and the element before the current r index in array a
        }
    } else { // If r is greater than or equal to the first element of array a
        // Print the value of c[r] directly as it is stored in c[r] itself
        cout << c[r] << endl; // Print the value of c[r] directly
    }
    
    // Additional logic for m=0 case: Check if there are any remaining elements to process after the loop iteration
    while (m--) {
        int l, r; // Input elements for processing loops
        cin >> l >> r; // Input elements for further processing
        // Fix to handle edge cases and constraint limits: The indices are provided in descending order so we can directly access them without worrying about bounds checks
        // Use an if statement to determine if l_i exists within the bounds of array a, and print accordingly if so
        if (l_i < n && l_i >= l) { // Access element c[l_i] if it exists within bounds and is within range
            cout << c[r] - c[l_i - a.begin() - 1] << endl; // Calculate and print the difference between element c[r] and the value stored at c[l_i] minus the difference between the previous value and the element before it in array a for that particular loop iteration
        } else { // If l_i is not within bounds, simply print as is without any calculation or difference computation for that particular case
            cout << c[r] << endl; // Print as is if l_i is not within bounds for that particular iteration of processing loops
        }
    }
    return 0; // Return 0 to indicate successful completion of program execution
}