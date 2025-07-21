#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    vector<ll> p(n), s(n + 1, 0); // Initialize s with 0 to avoid undefined behavior
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        for (int j = 0; j <= i; j++) { // Calculate prefix sum correctly
            s[i + 1] += p[j];
        }
    }
    
    int q;
    cin >> q;
    while (q--) { // Use a while loop for multiple queries
        int l, r;
        cin >> l >> r;
        // Find the indices of l and r in the sorted array x (binary search)
        auto it_l = lower_bound(x.begin(), x.end(), l);
        auto it_r = upper_bound(x.begin(), x.end(), r);
        int lt = it_l - x.begin(); // Correct index calculation for lower bound
        int rt = it_r - x.begin() - 1; // Subtract 1 because upper_bound returns one past the end of the range
        // Calculate the answer using the prefix sum array s (be careful of indices)
        ll ans = s[rt] - s[lt]; // Correct calculation using long long to avoid overflow
        cout << ans << endl; // Output the answer for each query
    }
    return 0;
}