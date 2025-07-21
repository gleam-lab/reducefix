#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n+1); // Assuming a is an array of integers
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // Assuming b and c are not used in this context, they can be removed or redefined if needed
    // ... (other code) ...
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r; // l and r are the query bounds
        // Find the indices of l and r in a (assuming a is sorted)
        auto l_i = lower_bound(a.begin(), a.end(), l); // 0-based index if a is 0-based internally
        auto r_j = upper_bound(a.begin(), a.end(), r); // 0-based index if a is 0-based internally
        int i = l_i - a.begin(); // Convert 0-based index to 1-based index if needed (depends on internal representation)
        int j = r_j - a.begin() - 1; // Decrement for 0-based index and subtract 1 for 1-based index (if necessary)
        // Assuming there's some prefix sum array (c) that we can use to calculate range queries...
        // If there's no such prefix sum or it's not used in this context, remove related code.
        // The correct output logic depends on what c represents and how it's used in this context.
        // ... (output logic based on c and other variables) ...
    }
    return 0;
}