#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> x(n); // This array is not used in the correct solution.
    for (int i = 0; i < n; i++) cin >> x[i]; // Reading but not using x[i]
    vector<ll> p(n), s(n+1);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        s[i+1] = s[i] + p[i];
    }
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; // Convert 1-based index to 0-based
        r--; // Convert 1-based index to 0-based (adjust if needed based on problem statement)
        // Note: Adjust r if the problem requires exclusive upper bound
        ll ans = s[r+1] - s[l]; // Use prefix sums to find the range sum
        cout << ans << endl;
    }
    return 0;
}