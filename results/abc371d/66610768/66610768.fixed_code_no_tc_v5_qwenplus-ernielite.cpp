#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6; // Changed to 1e6 to avoid potential array size issues

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1, 0); // Initialized c with zeros
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i]; // Assuming b is a copy of a for this problem (needs clarification)
    }
    // Compute prefix sum of b (stored in c)
    for (int i = 1; i <= n; i++) {
        if (i > 1) c[i] = c[i - 1] + b[i]; // Initialize c[1] with 0 or appropriate value based on problem context
        else c[i] = b[i]; // Initialize c[1] with the first element of b if needed
    }
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        // Perform binary search to find the left index in a for the given query l
        auto l_i = lower_bound(a.begin() + 1, a.end(), l);
        // If l is not found, l_i will point to the first element greater than l or end() if not found. Adjust accordingly.
        if (l_i == a.begin() || *l_i != l) l_i--; // Adjust if l is not found exactly at the beginning of the range.
        // Perform binary search to find the right index in a for the given query r (exclusive)
        auto r_j = upper_bound(a.begin() + 1, a.end(), r); // This will point to the first element greater than or equal to r.
        int i = l_i - a.begin(); // Corrected index calculation for l_i.
        int j = (r_j - a.begin() > 0) ? (r_j - a.begin() - 1) : n; // Corrected index calculation for r_j, handling out-of-bounds case.
        // Output the result based on the problem's requirements (needs clarification)
        // The following line is a placeholder and needs to be replaced with the correct logic based on the problem's context.
        cout << (r >= n || c[j] == 0) ? "Invalid" : c[j] << endl; // Placeholder output based on problem's context (replace with actual logic)
    }
    return 0;
}