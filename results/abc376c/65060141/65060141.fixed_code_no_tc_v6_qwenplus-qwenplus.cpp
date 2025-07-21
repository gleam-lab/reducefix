#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 200005;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;
    
    vector<ll> A(n), B(n - 1);
    
    for (ll i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    for (ll i = 0; i < n - 1; ++i) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    // Try to fit largest toys into largest boxes
    ll extra_toy = -1;
    
    int a_idx = n - 1;
    int b_idx = n - 2;
    
    while (a_idx >= 0 && b_idx >= 0) {
        if (B[b_idx] >= A[a_idx]) {
            // Box can fit this toy
            a_idx--;
            b_idx--;
        } else {
            // This toy cannot fit in any available box, we might need a new box for it
            if (extra_toy == -1) {
                extra_toy = A[a_idx];
            } else {
                // We already had one toy that didn't fit, and now another -- impossible
                cout << -1 << endl;
                return 0;
            }
            a_idx--;
        }
    }
    
    // If there's still an unmatched toy
    if (extra_toy == -1 && a_idx >= 0) {
        extra_toy = A[a_idx];
    }
    
    if (extra_toy == -1) {
        // All toys matched perfectly
        cout << 0 << endl;
    } else {
        cout << extra_toy << endl;
    }

    return 0;
}