#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = b[i - 1] + a[i]; // Accumulate prefix sum of a
        c[i] = b[i]; // c can be the same as b since we only need prefix sum
    }
    
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        // Find the indices in a where l and r are present (since we start with 1)
        auto l_i = lower_bound(a.begin() + 1, a.end(), l) - a.begin();
        auto r_j = upper_bound(a.begin() + 1, a.end(), r) - a.begin() - 1; // Subtract 1 as we want to exclude r from the sum
        
        // Check if l is valid (not out of bounds) and if r is valid (not equal to n)
        if (l_i > 0 && r_j < n) {
            // Calculate the sum of c between l_i and r_j (inclusive)
            int sum = b[r_j] - b[l_i - 1]; // Corrected calculation of range sum query
            if (r >= a[n]) { // If r is equal to the last element in a, we need to adjust the sum accordingly
                sum += c[n]; // Add the last element in c (c[n] = b[n])
            }
            cout << sum << endl; // Output the result
        } else {
            // If l or r is out of bounds, output an appropriate message or handle it as needed (e.g., -1)
            cout << "Invalid query" << endl; // Example output for invalid query, you can replace it with your desired behavior
        }
    }
    return 0;
}