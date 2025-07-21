#include <bits/stdc++.h>
using namespace std;

int n, q;
int x[200005];  // x is now used for both array elements and prefix sum
int p[200005];  // p is used to store the actual values for sum
int sum[200005]; // Sum of elements in x for a particular range

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i]; // Read the elements into x
        p[i] = x[i]; // Initialize p with the same values as x for prefix sum calculation
        sum[i] = (i > 1) ? sum[i - 1] + p[i] : p[i]; // Initialize sum array with prefix sum calculation
    }
    
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R; // Read the range query
        
        // The use of lower_bound and upper_bound is unnecessary in this case, we're not actually working with sorted arrays. 
        // We simply need to access the prefix sum values correctly.
        // However, if x is indeed sorted, we can keep the logic as it is.
        // If not, we should remove the binary search logic and use direct indexing.
        
        // The output should be the difference between the prefix sums at R-1 and L (inclusive). 
        // However, we need to make sure R is within bounds (n+1 for the prefix sum array).
        int l = L - 1; // Adjust index to be within the bounds of x/sum array
        int r = R > n ? n : R - 1; // Ensure R does not go out of bounds for sum array
        cout << (r > l) ? sum[r] - sum[l] : 0 << endl; // Check if r is within bounds before subtracting prefix sums
    }
    return 0; // Return 0 to indicate successful completion of main function
}