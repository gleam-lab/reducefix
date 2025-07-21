#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> A(n), B(n - 1);
    for (ll i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (ll i = 0; i < n - 1; i++) {
        cin >> B[i];
    }
    
    // Sort the sizes for easier comparison
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    // Initialize the answer as the size of the smallest toy that cannot fit into any box
    ll ans = 1;
    
    // Check if each toy can fit into one of the existing boxes
    for (ll i = 0; i < n; i++) {
        ll lower = 0, upper = n - 1;
        // Binary search to find if the current toy can fit into any of the existing boxes
        while (lower <= upper) {
            ll mid = (lower + upper) / 2;
            if (A[i] <= B[mid]) {
                // If the toy can fit into the box at index mid, no need to consider larger boxes
                upper = mid - 1;
            } else {
                // If the toy cannot fit, assume it can fit into a new box of at least size A[i]
                ans = max(ans, A[i]);
                lower = mid + 1;
            }
        }
    }
    
    // If the answer is still 1, it means all toys can fit into one of the existing boxes
    if (ans == 1) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}

int main() {
    solve();
    return 0;
}