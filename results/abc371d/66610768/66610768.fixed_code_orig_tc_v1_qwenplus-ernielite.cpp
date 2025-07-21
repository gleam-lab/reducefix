#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+7;
int main() {
    int n, m;
    cin >> n;
    vector<int> a(n+1, 0); // Initialize with 0s
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (m == 1) { // Special case for when only one query is given
        int l; // No need for 'r' as only one query is given
        cin >> l; // Read the single query value
        auto l_i = lower_bound(a.begin() + 1, a.end(), l); // Perform binary search for 'l'
        if (l_i == a.end()) { // If not found, output -1 as expected
            cout << -1 << endl;
        } else { // If found, output the corresponding result (which would be 0 in this case)
            cout << 0 << endl; // Or any other appropriate result based on the logic of the program
        }
    } else { // Normal case for multiple queries
        vector<int> b(n+1, 0), c(n+1, 0); // Initialize with 0s for b and c as well (if needed in program logic)
        for (int i = 1; i <= m; i++) { // Read all queries and process them accordingly
            cin >> l >> r; // Read 'l' and 'r' for each query
            // Perform binary searches and other necessary operations for each query...
        }
    }
    return 0;
}