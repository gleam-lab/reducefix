#include<bits/stdc++.h>
using namespace std;

int n, q;
int x[200005], p[200005];
int sum[200005]; // Sum of p from 1 to i

// Function to calculate prefix sum of p
void calculateSum(int arr[], int n) {
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + p[i];
    }
}

// Function to perform binary search for a value in a sorted array
int binarySearch(int arr[], int n, int target) {
    int low = 1, high = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid; // Return index if found
        } else if (arr[mid] < target) {
            low = mid + 1; // Increase lower bound
        } else {
            high = mid - 1; // Decrease upper bound
        }
    }
    return -1; // Return -1 if not found (or handle it as needed)
}

int main() {
    cin >> n; // Read number of elements in x and p arrays
    for (int i = 1; i <= n; i++) {
        cin >> x[i]; // Read elements of x array
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i]; // Read elements of p array and calculate prefix sum
        sum[i] = sum[i - 1] + p[i]; // Store sum of p in sum array (not really needed here)
    }
    sort(x + 1, x + n + 1); // Sort the x array for binary search later on
    calculateSum(p, n); // Calculate prefix sum of p only once (optional)
    cin >> q; // Read number of queries
    while (q--) {
        int l, r; // Read left and right values for query range
        cin >> l >> r; // Get query values from input (assuming l <= r)
        l = binarySearch(x, n, l); // Perform binary search for left value in x array to get index
        r = binarySearch(x, n, r) + 1; // Perform binary search for right value in x array to get index (inclusive)
        if (l == -1 || r == -1 || l > r) { // Check if query is valid or not (e.g., l > r)
            cout << "Invalid query" << endl; // Handle invalid query as needed (e.g., print error message)
            continue; // Skip this query and continue with next one if needed
        } else { // Calculate and print result for valid query range (l <= r)
            cout << sum[r] - sum[l] << endl; // Output result by subtracting sum of p at left from sum at right for range [l, r] (inclusive)
        }
    }
    return 0; // Exit main function after all queries are processed and results are printed (optional)
}