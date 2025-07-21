#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 1e6+7;
int main() {
    int n, m;
    cin >> n;
    vector<int> a(n+1, 0), b(n+1, 0), c(n+1, 0); // Initialize all vectors with size n+1 to avoid out-of-bounds errors.
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; // Read values into array a.
        b[i] = b[i - 1] + a[i]; // Calculate prefix sum of a.
        c[i] = b[i] - b[0]; // Calculate cumulative sum for each element.
    }
    cin >> m; // Read number of queries.
    while (m--) {
        int l, r;
        cin >> l >> r; // Read query range.
        auto l_i = lower_bound(a.begin() + 1, a.end(), l); // Find index of lower bound for left value.
        auto r_j = upper_bound(a.begin() + 1, a.end(), r); // Find index of upper bound for right value.
        int i = l_i - a.begin() - 1; // Convert left index to actual array index (subtracting 1 since we start counting at 1).
        int j = r_j - a.begin() - 1; // Convert right index to actual array index (subtracting 1).
        if (r >= a[n]) { // Check if right value is greater than or equal to maximum value in a.
            cout << c[n] - b[i] << endl; // Calculate range sum as total sum minus sum before left index.
        } else { // Otherwise, calculate range sum as difference between two cumulative sums.
            cout << b[j] - b[i] << endl; // Outputting the correct range sum based on indices i and j.
        }
    }
    return 0;
}