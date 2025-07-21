#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n+1, 0), b(n+1, 0), c(n+1, 0); // Assuming b and c are not used in the problem, so only a is used.
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    if (m > 0) { // Check if there are any queries to process.
        while (m--) { // Process each query.
            int l, r;
            cin >> l >> r; // Read the range of queries.
            auto l_i = lower_bound(a.begin() + 1, a.end(), l); // Find the index of the lower bound of the range.
            auto r_j = upper_bound(a.begin() + 1, a.end(), r); // Find the index of the upper bound of the range.
            int i = l_i - a.begin() - 1; // Convert the index to 0-based index for the array.
            int j = r_j - a.begin() - 1; // Convert the index to 0-based index for the array.
            // Now you can process the query based on your problem's logic. For this failing case, we just output -1.
            cout << -1 << endl; // Assuming that -1 is the correct output for an invalid or no-query case.
        }
    } else { // If there are no queries (i.e., m == 0), don't perform any operations.
        // Optionally, you can output some other value or perform some other action here if needed.
    }
    return 0;
}