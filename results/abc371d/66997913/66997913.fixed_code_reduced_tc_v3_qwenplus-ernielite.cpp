#include <bits/stdc++.h>
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
        s[i + 1] = s[i] + p[i]; // Corrected the prefix sum calculation
    }
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        // Convert the queries to 1-based indexing for the prefix sum array s
        int lt = lower_bound(x.begin(), x.end(), l) - x.begin() + 1; // +1 for 1-based indexing
        int rt = upper_bound(x.begin(), x.end(), r) - x.begin(); // No need to subtract x.begin() here as we're just finding the index
        if (lt > rt) continue; // Skip queries where l is greater than r (invalid range)
        // Now calculate the answer using the prefix sum array s
        ll ans = s[rt] - s[lt - 1]; // Corrected the index to subtract s[lt - 1] instead of s[lt] (to get the correct prefix sum)
        cout << ans << endl;
    }
    return 0;
}