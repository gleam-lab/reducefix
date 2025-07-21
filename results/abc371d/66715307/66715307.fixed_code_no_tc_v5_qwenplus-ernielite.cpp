#include <bits/stdc++.h>
using namespace std;

int n, x[200050], p[200050], q, a[200050];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i]; // Accumulate prefix sum of p
    }

    cin >> q;
    while (q--) { // Use a while loop for multiple queries
        int l, r;
        cin >> l >> r;
        
        // Binary search for the left index (l1) in the x array for the given l value
        int l1 = 1, r1 = n;
        while (l1 < r1) {
            int mid = l1 + (r1 - l1) / 2; // Use this instead of l1+r1>>1 to avoid overflow
            if (x[mid] >= l) r1 = mid;
            else l1 = mid + 1;
        }
        // If l1 is still greater than the right index, it means the value is not present in x array. Handle this case appropriately.
        if (l1 > n) {
            // Handle the case where l is too large or not present in x array.
            // For example, you can set l1 to n + 1 or some other appropriate value.
            continue; // Or return an error/special value.
        }
        
        // Binary search for the right index (l2) in the x array for the given r value, but one position to the left (since a is shifted by 1)
        int l2 = 0, r2 = n - 1; // Start from 0 since a[0] is not defined and we want to find the index before l1.
        while (l2 <= r2) { // Use <= instead of < to include the right boundary.
            int mid = l2 + (r2 - l2 + 1) / 2; // Again, use this to avoid overflow and consider the extra +1 for the shift in a array.
            if (x[mid] <= r) l2 = mid; // Here we check for less than or equal to r since we want the index that includes r in the x array.
            else r2 = mid - 1; // Update r2 accordingly.
        }
        // If l2 is still negative, it means the value is not present in x array within the shifted range. Handle this case appropriately.
        if (l2 < 0) {
            // Handle the case where r is too small or not present in the shifted x array.
            continue; // Or return an error/special value.
        }
        // Calculate and print the result using a[l2-1] as we want the prefix sum up to and including l2-1 in a.
        cout << a[l2 - 1] << endl; // Adjusting for the shift in a[] by subtracting 1 from l2.
    }
    return 0;
}