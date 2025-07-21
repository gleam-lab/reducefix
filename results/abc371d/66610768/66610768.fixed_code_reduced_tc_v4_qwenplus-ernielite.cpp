#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n+1), c(n+1); // b is not used in this problem, so we can remove it
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    c[0] = 0; // Initialize c[0] to 0 to make sure prefix sum is correct at index 1
    for (int i = 1; i <= n; i++) {
        c[i] = c[i - 1] + a[i]; // Calculate prefix sum of a
    }
    
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        auto l_i = lower_bound(a.begin(), a.end(), l) - a.begin(); // Corrected lower_bound usage
        auto r_j = upper_bound(a.begin(), a.end(), r) - a.begin() - 1; // Corrected upper_bound usage for '>' instead of '>='
        if (r_j > 0) { // Check if there is an element greater than r before using it as an index
            // Calculate sum of elements in c between l_i and r_j (inclusive)
            cout << c[r_j] - c[l_i] << endl; // Corrected range sum query calculation
        } else {
            // If there's no such element in a for r, then it's possible that r is greater than any element in a.
            // In this case, we need to calculate the sum from the end of c up to the index before l_i.
            cout << c[n] - c[l_i - 1] << endl; // Corrected calculation for greater-than case
        }
    }
    return 0;
}